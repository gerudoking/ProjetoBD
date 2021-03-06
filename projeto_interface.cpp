#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <windows.h>
#include <winsock2.h>
#include <mysql.h>

//#define DEBUG_SQL

using namespace std;

string uintToStr ( unsigned int number )  // Converte um inteiro sem sinal para uma string com seus algarismos
{
  unsigned int decimals = log10(number), copy = number;
  string algarisms;

  for ( int i = decimals; i >= 0; i-- )
  {
    algarisms += (copy/(unsigned int)pow(10, i) + '0');
    copy = copy%(unsigned int)pow(10, i);
  }

  return algarisms;
}

struct Entidade {
  string nome;
  vector<string> atributo;
};

int main ( int argc, char *argv[] )
{
  system( "chcp 1252 > nul" );

  MYSQL conn;

  mysql_init(&conn);

	if( mysql_real_connect( &conn, "localhost", "root", "root", "transporte", 3306, NULL, 0 ) )
	{
    cout << "Conectado com o Banco de Dados" << endl;

    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;

    vector<Entidade> entidades;
    vector<string> atributosInseridos;
    vector<unsigned int> tabs;
    string tmpString, sqlCommand;
    int opcao = -1, primeiro;
    unsigned int nroEntidade, nroElemento;

    entidades.push_back( Entidade() );
    entidades.back().nome = "condutor";
    entidades.back().atributo.push_back( "Nome" );
    entidades.back().atributo.push_back( "CPF" );
    entidades.back().atributo.push_back( "RG" );
    entidades.back().atributo.push_back( "Órgão Expedidor" );
    entidades.back().atributo.push_back( "Data de nascimento" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "habilitacao";
    entidades.back().atributo.push_back( "Número" );
    entidades.back().atributo.push_back( "Validade" );
    entidades.back().atributo.push_back( "Categoria" );
    entidades.back().atributo.push_back( "UF" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "veiculo";
    entidades.back().atributo.push_back( "Placa" );
    entidades.back().atributo.push_back( "Chassi" );
    entidades.back().atributo.push_back( "idEmpresa" );
    entidades.back().atributo.push_back( "idCondutor" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "marca_veiculo";
    entidades.back().atributo.push_back( "Nome Comercial" );
    entidades.back().atributo.push_back( "Nome Fantasia" );
    entidades.back().atributo.push_back( "Tipo" );
    entidades.back().atributo.push_back( "Sede" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "categoria_veiculo";
    entidades.back().atributo.push_back( "Nome" );
    entidades.back().atributo.push_back( "Número de rodas" );
    entidades.back().atributo.push_back( "Tração" );
    entidades.back().atributo.push_back( "Tipo" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "empresa_transporte";
    entidades.back().atributo.push_back( "Nome Comercial" );
    entidades.back().atributo.push_back( "Nome Fantasia" );
    entidades.back().atributo.push_back( "Tipo" );
    entidades.back().atributo.push_back( "Sede" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "empregado_emp_trans";
    entidades.back().atributo.push_back( "Nome" );
    entidades.back().atributo.push_back( "CPF" );
    entidades.back().atributo.push_back( "RG" );
    entidades.back().atributo.push_back( "Órgão Expedidor" );
    entidades.back().atributo.push_back( "Data de nascimento" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "telefone_empregado";
    entidades.back().atributo.push_back( "Telefone" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "cobrador";
    entidades.back().atributo.push_back( "Escolaridade" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "motorista";
    entidades.back().atributo.push_back( "CNH" );
    entidades.back().atributo.push_back( "Nome" );
    entidades.back().atributo.push_back( "Validade CNH" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "local";
    entidades.back().atributo.push_back( "Nome" );
    entidades.back().atributo.push_back( "Descrição" );
    entidades.back().atributo.push_back( "CEP" );
    entidades.back().atributo.push_back( "Tipo" );
    entidades.back().atributo.push_back( "UF" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "infracao";
    entidades.back().atributo.push_back( "Situação" );
    entidades.back().atributo.push_back( "Data" );
    entidades.back().atributo.push_back( "Vencimento" );
    entidades.back().atributo.push_back( "Velocidade aferida" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "tipo_infracao";
    entidades.back().atributo.push_back( "Descrição" );
    entidades.back().atributo.push_back( "Classificação" );
    entidades.back().atributo.push_back( "Pontuação" );
    entidades.back().atributo.push_back( "Valor" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "via";
    entidades.back().atributo.push_back( "Identificação" );
    entidades.back().atributo.push_back( "Classificação" );
    entidades.back().atributo.push_back( "Velocidade" );
    entidades.back().atributo.push_back( "UF" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "sinalizacao";
    entidades.back().atributo.push_back( "Descrição" );
    entidades.back().atributo.push_back( "Tipo" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "fiscalizacao";

    entidades.push_back( Entidade() );
    entidades.back().nome = "orgao_transito";
    entidades.back().atributo.push_back( "Nome" );
    entidades.back().atributo.push_back( "Descrição" );

    entidades.push_back( Entidade() );
    entidades.back().nome = "funcionario_orgao";
    entidades.back().atributo.push_back( "Nome" );
    entidades.back().atributo.push_back( "CPF" );
    entidades.back().atributo.push_back( "RG" );
    entidades.back().atributo.push_back( "Órgão Expedidor" );
    entidades.back().atributo.push_back( "Função" );
    entidades.back().atributo.push_back( "Data de nascimento" );

    cout << "Bem vindo ao Banco de Dados de Transporte do Governo do Distrito Federal" << endl;

    while ( opcao != 0 )
    {
      cout << endl << "Escolha uma operação para executar no Banco de Dados: " << endl;
      cout << "1 - Inserir um novo elemento" << endl;
      cout << "2 - Visualizar uma tabela" << endl;
      cout << "3 - Modificar um elemento" << endl;
      cout << "4 - Remover um elemento" << endl;
      cout << "0 - Sair" << endl;
      cout << "Opção: ";
      cin >> opcao;
      cout << endl;

      switch ( opcao )
      {
      case 0:

        break;

      case 1:
        cout << "Escolha uma entidade para inserir: " << endl;

        for ( unsigned int i = 0; i < entidades.size(); i++ )
          cout << i + 1 << " - " << entidades[i].nome << endl;

        cout << "Entidade: ";
        cin >> nroEntidade;
        if ( nroEntidade > 0 && nroEntidade <= entidades.size() )
        {
          cout << endl << "Escolhida a entidade: '" << entidades[nroEntidade - 1].nome << "'" << endl;

          for ( unsigned int i = 0; i < entidades[nroEntidade - 1].atributo.size(); i++ )
          {
            cout << "Insira um dado para o atributo '" << entidades[nroEntidade - 1].atributo[i] << "': ";
            cin >> tmpString;
            atributosInseridos.push_back( tmpString );
            tmpString.clear();
          }

          //Insert SQL
          sqlCommand = "INSERT INTO `transporte`.`" + entidades[nroEntidade - 1].nome + "` (";
          for ( unsigned int i = 0; i < entidades[nroEntidade - 1].atributo.size(); i++ )
          {
            sqlCommand += "`" + entidades[nroEntidade - 1].atributo[i] + "`, ";
          }
          sqlCommand[sqlCommand.size() - 2] = ')';
          sqlCommand += "VALUES (";
          for ( unsigned int i = 0; i < atributosInseridos.size(); i++ )
          {
            sqlCommand += "'" + atributosInseridos[i] + "', ";
          }
          sqlCommand[sqlCommand.size() - 2] = ')';
          sqlCommand[sqlCommand.size() - 1] = ';';
#ifdef DEBUG_SQL
          cout << sqlCommand << endl;
#endif
          if ( mysql_query( &conn, sqlCommand.c_str() ) )
            cout << endl << "Não foi possével armazenar os dados informados. Tente novamente!" << endl;
          else
            cout << endl << "Dados armazenados com sucesso!" <<endl;

          sqlCommand.clear();
          for ( unsigned int i = 0; i < entidades[nroEntidade - 1].atributo.size(); i++ )
            atributosInseridos[i].clear();
          atributosInseridos.clear();
        }
        else
          cout << endl << "Entidade inválida! " << endl;

        break;

      case 2:
        cout << "Escolha uma entidade para visualizar: " << endl;

        for ( unsigned int i = 0; i < entidades.size(); i++ )
          cout << i + 1 << " - " << entidades[i].nome << endl;

        cout << "Entidade: ";
        cin >> nroEntidade;

        if ( nroEntidade > 0 && nroEntidade <= entidades.size() )
        {
          cout << endl << "Escolhida a entidade: '" << entidades[nroEntidade - 1].nome << "'" << endl;

          // Insert SQL
          sqlCommand += "SELECT * FROM " + entidades[nroEntidade - 1].nome + ";";
#ifdef DEBUG_SQL
          cout << sqlCommand << endl;
#endif
          mysql_query( &conn, sqlCommand.c_str() );
          result = mysql_store_result( &conn );
          sqlCommand.clear();


          while (( field = mysql_fetch_field( result ) ))
          {
            cout << field->name;

            tabs.push_back( strlen( field->name ) / 8 );
            cout << '\t';
          }
          cout << endl;

          while (( row = mysql_fetch_row( result ) ))
          {
              for( unsigned int i = 0; i < mysql_num_fields( result ); i++ )
              {
                  cout << row[i];

                  for ( unsigned int j = 0; j <= tabs[i]; j++ )
                    cout << '\t';
              }
              cout << endl;
          }
        }
        else
          cout << endl << "Entidade inválida! " << endl;

        break;

      case 3:
        cout << "Escolha uma entidade para modificar: " << endl;

        for ( unsigned int i = 0; i < entidades.size(); i++ )
          cout << i + 1 << " - " << entidades[i].nome << endl;

        cout << "Entidade: ";
        cin >> nroEntidade;

        if ( nroEntidade > 0 && nroEntidade <= entidades.size() )
        {
          cout << endl << "Escolhida a entidade: '" << entidades[nroEntidade - 1].nome << "'" << endl;
          cout << "Escolha o elemento da entidade: ";
          cin >> nroElemento;

          cout << endl << "Para cada atributo do elemento '" << nroElemento << "', insira um dado" << endl;
          for ( unsigned int i = 0; i < entidades[nroEntidade - 1].atributo.size(); i++ )
          {
            cout << "Insira um dado para o atributo '" << entidades[nroEntidade - 1].atributo[i] << "': ";
            cin >> tmpString;
            atributosInseridos.push_back( tmpString );
            tmpString.clear();
          }

          // Insert SQL
          sqlCommand = "UPDATE `transporte`.`" + entidades[nroEntidade - 1].nome + "` SET";

          primeiro = 0;
          for ( unsigned int i = 0; i < atributosInseridos.size(); i++ )
          {
            if ( primeiro != 0 )
              sqlCommand += ",";
            else
              primeiro = 1;

            sqlCommand += " `" + entidades[nroEntidade - 1].atributo[i] + "`='" + atributosInseridos[i] + "'";
          }

          sqlCommand += " WHERE `id`='" + uintToStr( nroElemento ) + "';";
#ifdef DEBUG_SQL
          cout << sqlCommand << endl;
#endif
          if ( mysql_query( &conn, sqlCommand.c_str() ) )
            cout << endl << "Não foi possével efetuar a modificação. Tente novamente!" << endl;
          else
            cout <<  endl << "Modificação efetuada com sucesso!" << endl;
          sqlCommand.clear();

          for ( unsigned int i = 0; i < entidades[nroEntidade - 1].atributo.size(); i++ )
            atributosInseridos[i].clear();
          atributosInseridos.clear();
        }
        else
          cout << endl << "Entidade inválida! " << endl;

        break;

      case 4:
        cout << "Escolha uma entidade para remover: " << endl;

        if ( nroEntidade > 0 && nroEntidade <= entidades.size() )
        {
          for ( unsigned int i = 0; i < entidades.size(); i++ )
            cout << i + 1 << " - " << entidades[i].nome << endl;

          cout << "Entidade: ";
          cin >> nroEntidade;
          cout << endl << "Escolhida a entidade: '" << entidades[nroEntidade - 1].nome << "'" << endl;
          cout << "Escolha o elemento da entidade: ";
          cin >> nroElemento;

          // Insert SQL
          sqlCommand += "DELETE FROM `transporte`.`" + entidades[nroEntidade - 1].nome + "` WHERE `id`='" + uintToStr( nroElemento ) + "';";
#ifdef DEBUG_SQL
          cout << sqlCommand << endl;
#endif

          if (mysql_query( &conn, sqlCommand.c_str() )){
            cout << endl << "Não foi possivel remover o elemento. Tente novamente!" << endl;
          } else
            cout <<  endl << "O dado foi removido com sucesso!" << endl;

          sqlCommand.clear();
        }
        else
          cout << endl << "Entidade inválida! " << endl;

        break;

      default:
        cout << "Opção inválida! Por favor escolha outra opção" << endl;

        break;
      }
    }
  }
  else
  {
    cout << "Falha de conexão\n";
      cout << "Erro " << mysql_errno( &conn ) << " : " << mysql_error( &conn ) << endl;
  }

  return 0;
}
