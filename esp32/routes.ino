
void handleRoot() {
  server.send(200, "text/plain", "hello from the garden!");
}

void handleWater() {
  if(server.pathArg(0) == "on"){
    valveState = true;
  } else {
    valveState = false;
  }
  server.send(200, "text/plain", "Chaged water state");
}

void handleSensorData() {
  
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}