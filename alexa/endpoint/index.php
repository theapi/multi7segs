<?php
require_once 'config.php';

if (getBearerToken() != $config["token"]) {
  $text = "I've been told not to talk to strangers.";
} else {
  try {
    $context = stream_context_create(
      array(
        'http' => array(
          'timeout' => 1
        )
      )
    );

    $digit_values = filter_input_array(INPUT_GET, FILTER_SANITIZE_NUMBER_INT);
    $query = http_build_query($digit_values);

    $mode = filter_input(INPUT_GET, 'mode', FILTER_SANITIZE_ENCODED);
    if (!empty($mode)) {
        $query .= '&mode=' . $mode;
    }

    $json = file_get_contents($config["endpoint"] . '?' . $query, 0, $context);
    $data = json_decode($json);
    if (isset($data->digits)) {
      $text = "Ok, that's done";
    } else {
      $text = "Hmmm, I don't think that worked";
    }
  } catch (Exception $e) {
    $text = "Sorry, I got an error from the display.
    It said; " . $e->getMessage();
  }
}

$response = '{
  "response": {
    "outputSpeech": {
      "type": "PlainText",
      "text": "' . $text . '"
    }
  }
}';

header('Content-Type: application/json');
print $response;


/**
 * Get hearder Authorization
 */
function getAuthorizationHeader(){
    $headers = null;
    if (isset($_SERVER['Authorization'])) {
        $headers = trim($_SERVER["Authorization"]);
    }
    else if (isset($_SERVER['HTTP_AUTHORIZATION'])) { //Nginx or fast CGI
        $headers = trim($_SERVER["HTTP_AUTHORIZATION"]);
    } elseif (function_exists('apache_request_headers')) {
        $requestHeaders = apache_request_headers();
        // Server-side fix for bug in old Android versions (a nice side-effect of this fix means we don't care about capitalization for Authorization)
        $requestHeaders = array_combine(array_map('ucwords', array_keys($requestHeaders)), array_values($requestHeaders));
        //print_r($requestHeaders);
        if (isset($requestHeaders['Authorization'])) {
            $headers = trim($requestHeaders['Authorization']);
        }
    }
    return $headers;
}

/**
 * Get access token from header
 */
function getBearerToken() {
    $headers = getAuthorizationHeader();
    // HEADER: Get the access token from the header
    if (!empty($headers)) {
        if (preg_match('/Bearer\s(\S+)/', $headers, $matches)) {
            return $matches[1];
        }
    }
    return null;
}
