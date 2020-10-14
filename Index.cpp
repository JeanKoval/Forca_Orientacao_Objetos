#include <iostream>
#include <string>
using namespace std;

class Forca{
  public:
    int TENTATIVAS=3;
    string mensagem = "Jogando!";
    string palavras[12] = { "carro", "mercado", "ovelha", "computador", "dados", "teclado", "monitor", "janela", "arbusto", "grama", "copo", "gato"};

    char letra;
	  string palavra;

    int verificaLetra(char, string, string&);
    void menu(); 
    void jogar(string);  

    Forca(){
      //gera um número randômico usando o gerador padrão.
      //primeiro a semente
      srand(time(NULL));
      //agora o número randômico
      int n = rand() % 12; //divisão por 12 e pega o módulo pode ser zero até 11

      palavra = palavras[n];
    }          
 };

  int Forca::verificaLetra(char tentativa, string palavra, string&esconde){
      int matches=0;
      int comprimento = palavra.length();
      for (int i = 0; i< comprimento; i++){
        if (tentativa == esconde[i])
          return 0;

        if (tentativa == palavra[i]){
          esconde[i] = tentativa;
          matches++;
        }
      }
    return matches;
  };

  void Forca::menu(){
    cout<<"\n\tForca!";
    cout << "\n\tVocê ainda tem " << TENTATIVAS << " tentativas para acertar a palavra.";
    cout<<"\n\n\t"<<mensagem;
  };

  void Forca::jogar(string esconde){
    while (TENTATIVAS != 0){
      menu();
      cout << "\n\n\t" << esconde;
      cout << "\n\n\tEscolha uma letra: ";
      cin >> letra;

      if (verificaLetra(letra, palavra, esconde)==0){
        mensagem = "Errou.";
        TENTATIVAS = TENTATIVAS - 1;
      } else {
        mensagem = "Letra certa!";
      }

      if (palavra==esconde){
        mensagem = "Ganhou!!!";
        menu();
        cout << "\n\tA palavra era: " << palavra << endl;
        break;
      }
    }

    if(TENTATIVAS == 0)
      {
        mensagem = "Perdeu, Playboy!!!.";
        menu();
        cout << "\n\tA palavra era: " << palavra << endl;
      }

      cin.ignore(); //limpa o buffer de teclado
      cin.get(); //vai esperar outra letra.

  };

int main(int argc, char *argv[]) {
  Forca teste;      
	
	string esconde(teste.palavra.length(),'_');	

  teste.jogar(esconde); 
	
	return 0;
}// fim do main
