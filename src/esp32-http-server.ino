/* ESP32 HTTP IoT Server Example for Wokwi.com

  https://wokwi.com/arduino/projects/320964045035274834

  When running it on Wokwi for VSCode, you can connect to the 
  simulated ESP32 server by opening http://localhost:8180
  in your browser. This is configured by wokwi.toml.
*/

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <uri/UriBraces.h>

#define WIFI_SSID "Wokwi-GUEST"
#define WIFI_PASSWORD ""
// Defining the WiFi channel speeds up the connection:
#define WIFI_CHANNEL 6

WebServer server(80);

const int LED1 = 26;
const int LED2 = 27;
const int LED3 = 25;
const int LED4 = 33;
const int LED5 = 32;
const int LED6 = 14;

bool led1State = false;
bool led2State = false;
bool led3State = false;
bool led4State = false;
bool led5State = false;
bool led6State = false;

void setup(void) {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD, WIFI_CHANNEL);
  Serial.print("Connecting to WiFi ");
  Serial.print(WIFI_SSID);
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", sendHtml);
  server.on("/toggle/1", []() { toggleLed(1); });
  server.on("/toggle/2", []() { toggleLed(2); });
  server.on("/toggle/3", []() { toggleLed(3); });
  server.on("/toggle/4", []() { toggleLed(4); });
  server.on("/toggle/5", []() { toggleLed(5); });
  server.on("/toggle/6", []() { toggleLed(6); });

  server.begin();
  Serial.println("HTTP server started (http://localhost:8180)");
}

void loop(void) {
  server.handleClient();
  delay(2);
}

void toggleLed(int ledNumber) {
  bool ledState = false;
  switch (ledNumber) {
    case 1:
      led1State = !led1State;
      digitalWrite(LED1, led1State ? HIGH : LOW);
      ledState = led1State;
      break;
    case 2:
      led2State = !led2State;
      digitalWrite(LED2, led2State ? HIGH : LOW);
      ledState = led2State;
      break;
    case 3:
      led3State = !led3State;
      digitalWrite(LED3, led3State ? HIGH : LOW);
      ledState = led3State;
      break;
    case 4:
      led4State = !led4State;
      digitalWrite(LED4, led4State ? HIGH : LOW);
      ledState = led4State;
      break;
    case 5:
      led5State = !led5State;
      digitalWrite(LED5, led5State ? HIGH : LOW);
      ledState = led5State;
      break;
    case 6:
      led6State = !led6State;
      digitalWrite(LED6, led6State ? HIGH : LOW);
      ledState = led6State;
      break;
    default:
      Serial.println("LED inválido");
      break;
  }
  String jsonResponse = String("{\"state\":\"") + (ledState ? "on" : "off") + "\"}";
  server.send(200, "application/json", jsonResponse); 
}

void sendHtml() {
  String response = R"rawliteral(
      <!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Casa Inteligente</title>
    <style>
      html,
      body {
        font-family: Arial, sans-serif;
        margin: 0;
        padding: 0;
      }
      body {
        display: flex;
        justify-content: center;
        align-items: center;
        min-height: 100vh;
        background-color: #2c2f33;
        color: #fff;
      }
      h1 {
        text-align: center;
        margin-bottom: 1.5em;
        font-size: 2em;
      }
      .container {
        display: grid;
        grid-template-columns: repeat(3, minmax(200px, 1fr));
        gap: 1.5em;
        width: 90%;
        max-width: 1200px;
      }

      .card {
        display: flex;
        flex-direction: column;
        align-items: center;
        padding: 1em;
        background: #444;
        border-radius: 16px;
        box-shadow: 0 4px 8px rgba(0, 0, 0, 0.4);
        transition: transform 0.3s ease, box-shadow 0.3s ease;
      }
      .card:hover {
        transform: translateY(-5px);
        box-shadow: 0 8px 16px rgba(0, 0, 0, 0.5);
      }
      .card img {
        width: 60px;
        margin-bottom: 1em;
      }
      .card h3 {
        margin: 0.5em 0;
        font-size: 1.1em;
        color: #e0e0e0;
      }
      .btn {
        background-color: #616060;
        border: none;
        border-radius: 50%;
        color: #fff;
        width: 60px;
        height: 60px;
        display: flex;
        justify-content: center;
        align-items: center;
        font-size: 1.2em;
        cursor: pointer;
        transition: background-color 0.3s ease;
      }
      .btn.on {
        background-color: #4caf50;
      }
      .btn:hover {
        background-color: #4caf50;
      }
    </style>
  </head>
  <body>
    <div>
      <h1>Casa Inteligente</h1>
      <div class="container">
        <div class="card">
          <img
            src="https://cdn-icons-png.flaticon.com/512/2779/2779262.png"
            alt="Lâmpada"
          />
          <h3>Ligar luzes</h3>
          <button id="btn1" onclick="toggleLed(1)" class="btn">
                 <img
              src="https://en.nureyon.com/sample/36/power_symbol-1-p0.svg"
              alt="icone de liga-desliga"
            />
          </button>
        </div>
        <div class="card">
          <img
            src="https://cdn-icons-png.flaticon.com/512/5114/5114238.png"
            alt="Ar Condicionado"
          />
          <h3>Ligar ar condicionado</h3>
          <button id="btn2" onclick="toggleLed(2)" class="btn">
            <img
              src="https://en.nureyon.com/sample/36/power_symbol-1-p0.svg"
              alt="icone de liga-desliga"
            />
          </button>
        </div>
        <div class="card">
          <img
            src="https://cdn-icons-png.flaticon.com/512/124/124321.png"
            alt=""
            srcset=""
          />
          <h3>Abrir cortinas</h3>
          <button id="btn3" onclick="toggleLed(3)" class="btn">
            <img
              src="https://en.nureyon.com/sample/36/power_symbol-1-p0.svg"
              alt="icone de liga-desliga"
            />
          </button>
        </div>
        <div class="card">
          <img
            src="https://cdn-icons-png.flaticon.com/512/195/195149.png"
            alt=""
            srcset=""
          />
          <h3>Ligar Televisão</h3>
          <button id="btn4" onclick="toggleLed(4)" class="btn">
            <img
              src="https://en.nureyon.com/sample/36/power_symbol-1-p0.svg"
              alt="icone de liga-desliga"
            />
          </button>
        </div>
        <div class="card">
          <img
            src="https://cdn-icons-png.flaticon.com/512/878/878022.png"
            alt=""
            srcset=""
          />
          <h3>Ligar ventilador</h3>
          <button id="btn5" onclick="toggleLed(5)" class="btn">
            <img
              src="https://en.nureyon.com/sample/36/power_symbol-1-p0.svg"
              alt="icone de liga-desliga"
            />
          </button>
        </div>
        <div class="card">
          <img
            src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcReeedbZF1lkeHS-uuvNnwPAvZrbIgZaqYCTA&s"
            alt=""
            srcset=""
          />
          <h3>Ligar cafeteira</h3>
          <button id="btn6" onclick="toggleLed(6)" class="btn">
            <img
              src="https://en.nureyon.com/sample/36/power_symbol-1-p0.svg"
              alt="icone de liga-desliga"
            />
          </button>
        </div>
      </div>
    </div>
    <script>
    function toggleLed(ledNumber) {
      // Envia uma requisição para alternar o LED
      fetch(`/toggle/${ledNumber}`)
        .then(response => response.json())
        .then(data => {
          // Atualiza a classe do botão de acordo com o estado do LED retornado
          const button = document.getElementById(`btn${ledNumber}`);
          if (data.state === "on") {
            button.classList.add("on");
          } else {
            button.classList.remove("on");
          }
        })
        .catch(error => console.error("Erro ao alternar LED:", error));
    }
  </script>
  </body>
</html>
  )rawliteral";
  server.send(200, "text/html", response);
}
