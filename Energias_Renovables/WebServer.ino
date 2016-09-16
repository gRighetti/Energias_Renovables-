
 void WebServer(){
   
    EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // add a meta refresh tag, so the browser pulls again every 5 seconds:
          client.println("<meta http-equiv=\"refresh\" content=\"5\">");
          // output the value of each analog input pin
        //  for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
         //   int sensorReading = analogRead(analogChannel);
         //   client.print("analog input ");
         //   client.print(analogChannel);
         //   client.print(" is ");
         //   client.print(sensorReading);
         //   client.println("<br />");       
         // }
         
                              client.println("<head>");
	                          client.println("<title> UCC </title>");
                               client.println("<head>");
	                client.println("<body>");
				 client.println("<h1>Energia Renovable </h1>");
				 client.println("<h2>Informacion del Inversor</h2>");
				 client.println("<br/>");
					 client.println("<table border=\"3px\" cellspacing=\"15px\">");//problema de las comillas preguntar!!!!!
							 client.println("<tr>");
								 client.println("<td>REFERENCIA</td>");
								 client.println("<td>VALOR</td>");
							 client.println("</tr>");
                                                         client.println("<tr>");
                                                                 client.println("<td>ESTADO</td>");
								 client.print("<td>");
                                                                 client.print(ESTADO);
                                                                 client.print("</td>");
                                                         client.println("</tr>");

							 client.println("<tr>");
								 client.println("<td>Tension del inversor</td>");
								 client.print("<td>");
                                                                 client.print(TENSIONDELINVERSOR);
                                                                 client.print("</td>");
							 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>corriente del inversor</td>");
								 client.print("<td>");
                                                                 client.print(CORRIENTEDELINVERSOR);
                                                                 client.print("</td>");
							 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>Tension de linea</td>");
								 client.print("<td>");
                                                                 client.print(TENSIONDELINEA);
                                                                 client.print("</td>");
							 client.println("</tr>");
					                 client.println("<tr>");
								 client.println("<td>Corriente de linea</td>");
								 client.print("<td>");
                                                                 client.print(CORRIENTEDELINEA);
                                                                 client.print("</td>");
							 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>Frecuencia</td>");
								 client.print("<td>");
                                                                 client.print(freTenEnt);
                                                                 client.print("." );
                                                                 client.print(freTenDec);
                                                                 client.print("</td>");
							 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>Fase</td>");
								 client.print("<td>");
                                                                 client.print(FASE);
                                                                 client.print("</td>");
					         	 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>Temperatura</td>");
								 client.print("<td>");
                                                                 client.print(TEMPERATURA);
                                                                 client.print("</td>");
							 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>Otro</td>");
								 client.print("<td>");
                                                                 client.print(OTRO);
                                                                 client.print("</td>");
							 client.println("</tr>");
					client.println("</table>");
				
				
				
				
	              client.println("</body>");

          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}

