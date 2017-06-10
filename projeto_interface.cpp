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
  entidades.back().nome = "Habilitação";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Veículo";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Marca de veículo";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Categoria de veículo";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Empresa de transporte";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Local";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Infração";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Tipo de infração";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Via";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Sinalização";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Fiscalização";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Órgão de trânsito";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Funcionário do órgão";

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

      // Inserir SQL de inserção aqui

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
      cout << "Opção inválida, por favor escolha outra opção" << endl;
      break;
    }
  }

  return 0;
}
