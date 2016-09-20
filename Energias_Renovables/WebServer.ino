
 void WebServer(){
   
    EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    boolean linea=true;
    t="";
    int uno=0;
    int dos=0;
    while (client.connected()) {
      
      if (client.available()) {
        char c = client.read();
       // Serial.write(c);
        if(!(c=='\n') && linea){
        t+=(String)c;
        }else{
          linea=false;
        }
        
            
        //GET /HOla HTTP/1.1


        
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          Serial.println(t);
                
                Serial.println(t.indexOf('/'));
                Serial.println(t.indexOf(' ',(t.indexOf('/')+1)));
               t= t.substring (t.indexOf('/')+1,t.indexOf(' ',(t.indexOf('/')+1)) );
                Serial.println(t); 
            if(t=="inicio.html" || t=="" ){
              Serial.println("GET inicio.html");
              
            }
            if(t=="historial.html"){
              Serial.println("GET  Historial.html");
            }
            if(t=="mail.html"){
              Serial.println("GET  Mail.html");
            }         
         
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // add a meta refresh tag, so the browser pulls again every 5 seconds:
          client.println("<meta http-equiv=\"refresh\" content=\"5\">");
        
         
                              client.println("<head>");
	                          client.println("<title> UCC </title>");
                               client.println("<head>");
	                client.println("<body>");

                 
				 client.println("<h1>Energia Renovable </h1>");


 client.println("<table style=\"width:100%\">");
 client.println( " <tr>");
    client.println(" <td style=\"text-align: center;\"><a href=\"inicio.html\">INICIO</a></td>");
     client.println("<td style=\"text-align: center;\"><a href=\"historial.html\">HISTORIAL</a></td>");
     client.println("<td style=\"text-align: center;\"><a href=\"mail.html\">MAIL</a></td>");
    
   client.println("</tr>");
    

        
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
								 client.println("<td>Tension de RED</td>");
								 client.print("<td>");
                                                                 client.print(TensiondeRed);
                                                                 client.print("</td>");
							 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>Corriente de RED</td>");
								 client.print("<td>");
                                                                 client.print(CorrientedeRed);
                                                                 client.print("</td>");
							 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>Freccuencia</td>");
								 client.print("<td>");
                                                                 client.print(freTenEnt);
                                                                 client.print("." );
                                                                 client.print(freTenDec);
                                                                 client.print("</td>");
							 client.println("</tr>");
					                 client.println("<tr>");
								 client.println("<td>Desfasaje</td>");
								 client.print("<td>");
                                                                 client.print(desfEnt);
                                                                 client.print("&#176 ," );
                                                                 client.print(desfDec);
                                                                 client.print("</td>");
							 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>Tension de tierra</td>");
								 client.print("<td>");
                                                                 client.print(TensionTierra);
                                                                 client.print("</td>");
							 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>Tension interna</td>");
								 client.print("<td>");
                                                                 client.print(delTensInt);
                                                                 client.print("</td>");
					         	 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>Corriente interna</td>");
								 client.print("<td>");
                                                                 client.print(corrInt);
                                                                 client.print("</td>");
							 client.println("</tr>");
							 client.println("<tr>");
								 client.println("<td>Tension continua</td>");
								 client.print("<td>");
                                                                 client.print(tenCont);
                                                                 client.print("</td>");
							 client.println("</tr>");

              client.println("<tr>");
                 client.println("<td>Corriente continua</td>");
                 client.print("<td>");
                                                                 client.print(corrCont);
                                                                 client.print("</td>");
               client.println("</tr>");
               client.println("<tr>");
                 client.println("<td>Temperatura 1</td>");
                 client.print("<td>");
                                                                 client.print(temp11);
                                                                 client.print("." );
                                                                 client.print(temp12);
                                                                 client.print("</td>");
               client.println("</tr>");
               client.println("<tr>");
                 client.println("<td>Temperatura 2</td>");
                 client.print("<td>");
                                                                 client.print(temp21);
                                                                 client.print("." );
                                                                 client.print(temp22);
                                                                 client.print("</td>");
               client.println("</tr>");
               client.println("<tr>");
                 client.println("<td>Temperatura 3</td>");
                 client.print("<td>");
                                                                 client.print(temp31);
                                                                 client.print("." );
                                                                 client.print(temp32);
                                                                 client.print("</td>");
               client.println("</tr>");
               
               client.println("<tr>");
                 client.println("<td>Temperatura 4</td>");
                 client.print("<td>");
                                                                 client.print(temp41);
                                                                 client.print("." );
                                                                 client.print(temp42);
                                                                 client.print("</td>");
               client.println("</tr>");
               client.println("<tr>");
                 client.println("<td>Humedad</td>");
                 client.print("<td>");
                                                                 client.print(Humedad);
                                                                 client.print("</td>");
               client.println("</tr>");
               client.println("<tr>");
                 client.println("<td>PWM</td>");
                 client.print("<td>");
                                                                 client.print(PWM);
                                                                 client.print("</td>");
               client.println("</tr>");
					
					client.println("</table>");

        client.println("<h2>Actualizacion:");
         client.println("<br/>");
        client.println("Fecha: ");
        client.print(dia);
        client.print("/");
        client.print(mes);
        client.print("/");
        client.print(anio);
        
         client.println("<br/>");
        
        client.println("Hora:  ");
        client.print(hora);
        client.print(":");
        client.print(minuto);
        client.print(":");
        client.print(segundo);         
        client.println("</h2>");
				
				
				
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

