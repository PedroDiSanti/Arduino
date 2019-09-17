//incluir biblioteca pra leitura de dígitos
#include <Keypad.h> 
 
//aqui se coloca a sua senha
char* secretCode = "655"; 

//posição inical zerada
int position = 0;

//número linhas disponíveis
const byte rows = 4;

//número colunas disponíveis
const byte cols = 3;

//layout do teclado
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

//posições dos botões ligados
byte rowPins[numRows] = {9,8,7,6};
byte colPins[numCols] = {5,4,3,2};

//chamando a biblioteca e passando as nossas variáveis como parâmetros
Keypad keypad = Keypad(makeKeymap(keys),rowPins, colPins, rows, cols);

//botão vermelho = erro
int redPin = 8;

//botão verde = senha correta
int greenPin = 9;
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  setLocked(true);
} //iniciando o setup do problema
 
void loop()
{
  char key = keypad.getKey();
  if (key == '*' || key == '#') {
    position = 0;
    setLocked(true);
  }//se as teclas * ou # forem apertadas, o sistema trava
  if (key == secretCode[position]) {
    position++;
  }//se o dígito na posição x estiver correto, a posição é incrementada para sabermos qual será o próximo dígito
  delay(50);
}
 
void setLocked(int locked)
{
  if (locked) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  }//se estiver travado, luz vermelha on, luz verde off
  else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
  }//senão, luz vermelha off, luz verde on
}