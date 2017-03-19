var Alexa = require('alexa-sdk');
var request = require("request");
var config = require('./config.json');
var APP_ID = config.app_id;

exports.handler = function(event, context, callback) {
    var alexa = Alexa.handler(event, context);
    alexa.appId = APP_ID;
    alexa.registerHandlers(handlers);
    alexa.execute();
};

var handlers = {
    'LaunchRequest': function () {
        console.log('LaunchRequest');
        this.emit(':tell', 'Do you want to to do change something on the display?');
        //@todo this should be an :ask and handle the answer...
    },

    'SetDigitIntent': function () {
        var digit = this.event.request.intent.slots.Digit.value;
        var number = this.event.request.intent.slots.Number.value;
        if (isNaN(digit)) {
            this.emit(':tell', `I didn't here a digit. I heard ${digit}`);
        }
        else if (isNaN(number)) {
            this.emit(':tell', `I didn't here a number. I heard ${number}`);
        }
        else {
            var url = config.url + '?d' + digit +  '=' + number;
            console.log(url);
            var that = this;
            var options = {
              url: url,
              rejectUnauthorized: false,
              agent: false,
              headers: {
                'Authorization' : 'Bearer ' + config.token
              }
            };
            request.get(options, function(error, response, body) {
                //console.log(body);
                var d = JSON.parse(body);
                if (d.response.outputSpeech.type = "PlainText") {
                     that.emit(':tell', d.response.outputSpeech.text);
                 } else {
                     that.emit(':tell', "Sorry, I could not contact the display");
                 }
            });
        }
    }
 };
