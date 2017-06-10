#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Entidade {
  string nome;
  vector<string> atributo;
};

int main ( int argc, char *argv[] ) {
  vector<Entidade> entidades;
  vector<string> atributosInseridos;
  string tmpString;
  int opcao = -1, nroEntidade = -1;

  entidades.push_back( Entidade() );
  entidades.back().nome = "Condutor";
  entidades.back().atributo.push_back( "Nome" );
  entidades.back().atributo.push_back( "RG" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Habilita��o";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Ve�culo";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Marca de ve�culo";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Categoria de ve�culo";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Empresa de transporte";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Local";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Infra��o";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Tipo de infra��o";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Via";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Sinaliza��o";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Fiscaliza��o";

  entidades.push_back( Entidade() );
  entidades.back().nome = "�rg�o de tr�nsito";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Funcion�rio do �rg�o";

  cout << "Bem vindo ao Banco de Dados de Transporte do Governo Brasileiro" << endl;

  while ( opcao != 0 ) {
    cout << endl << "Escolha uma operacao para executar no Banco de Dados: " << endl;
    cout << "1 - Inserir um novo elemento" << endl;
    cout << "2 - Visualizar uma tabela" << endl;
    cout << "3 - Modificar um elemento" << endl;
    cout << "4 - Remover um elemento" << endl;
    cout << "0 - Sair" << endl;
    cout << "Opcao: ";
    cin >> opcao;
    cout << endl;

    switch ( opcao ) {
    case 0:
      break;
    case 1:
      cout << "Escolha uma entidade: " << endl;

      for ( unsigned int i = 0; i < entidades.size(); i++ )
        cout << i + 1 << " - " << entidades[i].nome << endl;

      cout << "Entidade: ";
      cin >> nroEntidade;
      cout << endl << "Escolhida a entidade: '" << entidades[nroEntidade - 1].nome << "'" << endl;

      for ( unsigned int i = 0; i < entidades[nroEntidade - 1].atributo.size(); i++ ) {
        cout << "Insira um dado para o atributo '" << entidades[nroEntidade - 1].atributo[i] << "': ";
        cin >> tmpString;
        atributosInseridos.push_back( tmpString );
        tmpString.clear();
      }

      // Inserir SQL de inser��o aqui

      for ( unsigned int i = 0; i < entidades[nroEntidade - 1].atributo.size(); i++ )
        atributosInseridos[i].clear();
      atributosInseridos.clear();

      break;
    case 2:

      break;
    case 3:

      break;
    case 4:

      break;
    default:
      cout << "Op��o inv�lida, por favor escolha outra op��o" << endl;
      break;
    }
  }

  return 0;
}
