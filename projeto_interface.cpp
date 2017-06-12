#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <winsock2.h>
#include <mysql/mysql.h>

using namespace std;


struct Entidade {
  string nome;
  vector<string> atributo;
};

int main ( int argc, char *argv[] ) {
    MYSQL conn;

    mysql_init(&conn);


	if(mysql_real_connect(&conn, "localhost", "root", "", "transporte", 3306, NULL, 0))
	{
        cout << "conectado \n";



  vector<Entidade> entidades;
  vector<string> atributosInseridos;
  string tmpString;
  int opcao = -1;
  unsigned int nroEntidade, nroElemento;

  entidades.push_back( Entidade() );
  entidades.back().nome = "Motorista";
  entidades.back().atributo.push_back( "ID" );
  entidades.back().atributo.push_back( "Nome" );
  entidades.back().atributo.push_back( "RG" );
  entidades.back().atributo.push_back( "Data de nascimento" );
  entidades.back().atributo.push_back( "Telefone" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Habilitacao";
  entidades.back().atributo.push_back( "Validade" );
  entidades.back().atributo.push_back( "UF" );
  entidades.back().atributo.push_back( "Orgao emissor" );
  entidades.back().atributo.push_back( "Categoria" );
  entidades.back().atributo.push_back( "RG" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Veiculo";
  entidades.back().atributo.push_back( "ID" );
  entidades.back().atributo.push_back( "ID da empresa" );
  entidades.back().atributo.push_back( "ID do condutor" );
  entidades.back().atributo.push_back( "Placa" );
  entidades.back().atributo.push_back( "Chassi" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Marca de veiculo";
  entidades.back().atributo.push_back( "ID" );
  entidades.back().atributo.push_back( "Nome comercial" );
  entidades.back().atributo.push_back( "Nome Fantasia" );
  entidades.back().atributo.push_back( "Tipo" );
  entidades.back().atributo.push_back( "Sede" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Categoria de veiculo";
  entidades.back().atributo.push_back( "ID" );
  entidades.back().atributo.push_back( "Nome" );
  entidades.back().atributo.push_back( "Quantidade de rodas" );
  entidades.back().atributo.push_back( "Tracao" );
  entidades.back().atributo.push_back( "Tipo" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Empresa de transporte";
  entidades.back().atributo.push_back( "ID" );
  entidades.back().atributo.push_back( "Nome comercial" );
  entidades.back().atributo.push_back( "Nome fantasia" );
  entidades.back().atributo.push_back( "Tipo" );
  entidades.back().atributo.push_back( "Sede" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Local";
  entidades.back().atributo.push_back( "ID" );
  entidades.back().atributo.push_back( "Descricao" );
  entidades.back().atributo.push_back( "CEP" );
  entidades.back().atributo.push_back( "Tipo" );
  entidades.back().atributo.push_back( "UF" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Infracao";
  entidades.back().atributo.push_back( "ID" );
  entidades.back().atributo.push_back( "Situacao" );
  entidades.back().atributo.push_back( "Data" );
  entidades.back().atributo.push_back( "Vencimento" );
  entidades.back().atributo.push_back( "Velocidade aferida" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Tipo de infracao";
  entidades.back().atributo.push_back( "ID" );
  entidades.back().atributo.push_back( "Descricao" );
  entidades.back().atributo.push_back( "Classificacao" );
  entidades.back().atributo.push_back( "Pontuacao" );
  entidades.back().atributo.push_back( "Valor" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Via";
  entidades.back().atributo.push_back( "ID" );
  entidades.back().atributo.push_back( "Identificacao" );
  entidades.back().atributo.push_back( "Classificacao" );
  entidades.back().atributo.push_back( "Velocidade" );
  entidades.back().atributo.push_back( "UF" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Sinalizacao";
  entidades.back().atributo.push_back( "ID" );
  entidades.back().atributo.push_back( "Descricao" );
  entidades.back().atributo.push_back( "Tipo" );
  entidades.back().atributo.push_back( "Atributo 2" );
  entidades.back().atributo.push_back( "Atributo 3" );

  entidades.push_back( Entidade() );
  entidades.back().nome = "Fiscalizacao";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Orgao de transito";

  entidades.push_back( Entidade() );
  entidades.back().nome = "Funcionario do orgao";

  cout << "Bem vindo ao Banco de Dados de Transporte do Governo do Distrito Federal" << endl;

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
      cout << "Escolha uma entidade para inserir: " << endl;

      for ( unsigned int i = 0; i < entidades.size(); i++ )
        cout << i + 1 << " - " << entidades[i].nome << endl;

      cout << "Entidade: ";
      cin >> nroEntidade;
      if ( nroEntidade > 0 && nroEntidade <= entidades.size() ) {
        cout << endl << "Escolhida a entidade: '" << entidades[nroEntidade - 1].nome << "'" << endl;

        for ( unsigned int i = 0; i < entidades[nroEntidade - 1].atributo.size(); i++ ) {
          cout << "Insira um dado para o atributo '" << entidades[nroEntidade - 1].atributo[i] << "': ";
          cin >> tmpString;
          atributosInseridos.push_back( tmpString );
          tmpString.clear();
        }

        //Insert SQL
       mysql_query(&conn,"INSERT INTO `transporte`.`condutor` (`Nome`, `CPF`, `RG`, `Órgão Expedidor`,`Data de nascimento`) VALUES ('Geovana', '03674875102', '26354','SSP', '19910526');");


        for ( unsigned int i = 0; i < entidades[nroEntidade - 1].atributo.size(); i++ )
          atributosInseridos[i].clear();
        atributosInseridos.clear();
      }
      else
        cout << endl << "Entidade invalida! " << endl;

      break;

    case 2:
      cout << "Escolha uma entidade para visualizar: " << endl;

      for ( unsigned int i = 0; i < entidades.size(); i++ )
        cout << i + 1 << " - " << entidades[i].nome << endl;

      cout << "Entidade: ";
      cin >> nroEntidade;

      if ( nroEntidade > 0 && nroEntidade <= entidades.size() ) {
        cout << endl << "Escolhida a entidade: '" << entidades[nroEntidade - 1].nome << "'" << endl;

        // Inserir SQL de visualização aqui
      }
      else
        cout << endl << "Entidade invalida! " << endl;

      break;

    case 3:
      cout << "Escolha uma entidade para modificar: " << endl;

      for ( unsigned int i = 0; i < entidades.size(); i++ )
        cout << i + 1 << " - " << entidades[i].nome << endl;

      cout << "Entidade: ";
      cin >> nroEntidade;

      if ( nroEntidade > 0 && nroEntidade <= entidades.size() ) {
        cout << endl << "Escolhida a entidade: '" << entidades[nroEntidade - 1].nome << "'" << endl;
        cout << "Escolha o elemento da entidade: ";
        cin >> nroElemento;

        cout << endl << "Para cada atributo do elemento '" << nroElemento << "', insira um dado para cada atributo" << endl;
        for ( unsigned int i = 0; i < entidades[nroEntidade - 1].atributo.size(); i++ ) {
          cout << "Insira um dado para o atributo '" << entidades[nroEntidade - 1].atributo[i] << "': ";
          cin >> tmpString;
          atributosInseridos.push_back( tmpString );
          tmpString.clear();
        }

        // Inserir SQL de modificação aqui

        for ( unsigned int i = 0; i < entidades[nroEntidade - 1].atributo.size(); i++ )
          atributosInseridos[i].clear();
        atributosInseridos.clear();
      }
      else
        cout << endl << "Entidade invalida! " << endl;

      break;

    case 4:
      cout << "Escolha uma entidade para remover: " << endl;

      if ( nroEntidade > 0 && nroEntidade <= entidades.size() ) {
        for ( unsigned int i = 0; i < entidades.size(); i++ )
          cout << i + 1 << " - " << entidades[i].nome << endl;

        cout << "Entidade: ";
        cin >> nroEntidade;
        cout << endl << "Escolhida a entidade: '" << entidades[nroEntidade - 1].nome << "'" << endl;
        cout << "Escolha o elemento da entidade: ";
        cin >> nroElemento;

        // Inserir SQL de remoção aqui
      }
      else
        cout << endl << "Entidade invalida! " << endl;
      break;

    default:
      cout << "Opcao invalida! Por favor escolha outra opcao" << endl;
      break;
    }
  }
} else {
	    cout << "Falha de conexao\n";
        cout << "Erro %d : %s\n", mysql_errno(&conn), mysql_error(&conn);
        return 0;
    }
  return 0;
}
