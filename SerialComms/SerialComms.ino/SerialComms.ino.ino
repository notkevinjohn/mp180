
void setup() {  
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("Starting Repeater");
}

void loop() { 
  if(Serial.available() > 0 ){   
    parseCommand(serialMessage());
  }
}

String serialMessage(){
  String message = "";
   while(Serial.available() > 0) {
      message += char(Serial.read());
      delay(10);
    }
    return message;
}

void parseCommand(String message) {
  int op_index(message.indexOf("("));
  int cp_index(message.indexOf(")"));
  String function = message.substring(0, op_index);
  String arguments = message.substring(op_index+1, cp_index);    
  parseArguments(arguments);  
}

void parseArguments(String arguments) { 
  String args[100];
  initargs(args);
  int i = 0;
  bool cont = true;
  while(cont){
        int com_index(arguments.indexOf(","));
        if(com_index == -1){cont = false;}
        String arg = arguments.substring(0,com_index);
        args[i] = arg;
        arguments = arguments.substring(com_index+1, arguments.length());
        i++;
  }
  int len[1];
  trimArray(args, len);
  String command[len + 1]
  for(int i=
}

void initargs(String args[100]){
  for(int i=0; i<100; i++){
    args[i]="*";
  }
}

void trimArray(String args[100], int* argLen) {
  for(int i=0; i<100; i++){  
      if(args[i] == "*"){        
        argLen[0] = i;      
        break;
      }
    }
    /*String newArgs[index];
    for(int i=0; i<index; i++){
      newArgs[i] == args[i];      
    }
    //args = newArgs;
    argLen = index;*/
  }


