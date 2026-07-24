/*
  ESP32 Web Dashboard
  Features:
  - Live Temperature & Humidity
  - LED ON/OFF Control
*/

#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

#define LED_PIN 2

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);
DHT dht(DHTPIN, DHTTYPE);

bool ledState = false;

String webpage()
{
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<title>ESP32 Dashboard</title>

<meta name="viewport" content="width=device-width, initial-scale=1">

<style>

body{
font-family:Arial;
background:#f2f2f2;
text-align:center;
margin-top:40px;
}

.card{
background:white;
padding:20px;
margin:auto;
width:300px;
border-radius:10px;
box-shadow:0 0 10px gray;
}

button{
padding:12px 25px;
font-size:18px;
margin:10px;
cursor:pointer;
}

</style>

<script>

function refreshData(){

fetch("/data")
.then(response=>response.json())
.then(data=>{

document.getElementById("temp").innerHTML=data.temp+" °C";
document.getElementById("hum").innerHTML=data.hum+" %";

});

}

setInterval(refreshData,2000);

</script>

</head>

<body onload="refreshData()">

<div class="card">

<h2>ESP32 Web Dashboard</h2>

<h3>Temperature</h3>
<p id="temp">--</p>

<h3>Humidity</h3>
<p id="hum">--</p>

<button onclick="location.href='/toggle'">
Toggle LED
</button>

</div>

</body>
</html>

)rawliteral";

  return page;
}

void handleRoot()
{
  server.send(200,"text/html",webpage());
}

void handleData()
{
  float t=dht.readTemperature();
  float h=dht.readHumidity();

  String json="{\"temp\":\""+String(t,1)+"\",\"hum\":\""+String(h,1)+"\"}";

  server.send(200,"application/json",json);
}

void handleToggle()
{
  ledState=!ledState;

  digitalWrite(LED_PIN,ledState);

  server.sendHeader("Location","/");
  server.send(303);
}

void setup()
{
  Serial.begin(115200);

  pinMode(LED_PIN,OUTPUT);

  dht.begin();

  WiFi.begin(ssid,password);

  Serial.print("Connecting");

  while(WiFi.status()!=WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println();

  Serial.println(WiFi.localIP());

  server.on("/",handleRoot);
  server.on("/data",handleData);
  server.on("/toggle",handleToggle);

  server.begin();

  Serial.println("Web Server Started");
}

void loop()
{
  server.handleClient();
}