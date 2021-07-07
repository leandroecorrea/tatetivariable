#include <iostream>
#include <vector>
using namespace std;

//construir un juego con un array de dos dimensiones tipo ta te ti y cada vez que uno de los dos usuarios pone un dato hay que poner el tateti hasta que uno gane
//el tamaño del ta te ti tiene tamaño variable


struct dimensiones { int filas, columnas; };
vector<vector<string>> tableroTateti;
dimensiones TableroSize();
vector<vector<string>> TableroVacio(int filas, int columnas);
string HaganJuego(int filas, int columnas);
bool TatetiChecker(int filas, int columnas);


void main()
{
	string restart;
	cout << "TATETI" << endl;
	while (restart != "N")
	{
		dimensiones tablero = { TableroSize() };
		tableroTateti = TableroVacio(tablero.filas, tablero.columnas);
		restart = HaganJuego(tablero.filas, tablero.columnas);
	}
}
dimensiones TableroSize()
{
	bool juegoListo = false;
	int filasElegidas;
	int columnasElegidas;
	do
	{
		cout << "Defina el alto del tateti (minimo3)" << endl;
		cin >> filasElegidas;
		cout << "Defina el ancho del tateti (minimo3)" << endl;
		cin >> columnasElegidas;
		if (filasElegidas < 3 || columnasElegidas < 3)
		{
			cout << "El tateti no tiene el tamaño minimo para iniciar el juego" << endl;
		}
		else
		{
			juegoListo = true;
		}
	} while (juegoListo == false);
	juegoListo = false;
	return dimensiones{ filasElegidas, columnasElegidas };
}
vector<vector<string>> TableroVacio(int filas, int columnas)
{
	vector<vector<string>> tablaVector(filas, vector<string>(columnas));

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			tablaVector[i][j] = "-";
		}
	}

	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			cout << " | " << tablaVector[i][j] << " | ";
		}
		cout << endl;
	}
	return tablaVector;
}
string HaganJuego(int filas, int columnas)
{
	int numeroJugador = 1;
	int jugadasRealizadas = 0;
	int jugadasMaximas = filas * columnas;
	int posicionFila;
	int posicionColumna;
	bool tatetiDetectado = false;
	bool juegoTerminado = false;
	string opcion;
	while (juegoTerminado == false)
	{
		cout << "hace su jugada el jugador " << numeroJugador << endl;
		cout << "indique posicion fila" << endl;
		cin >> posicionFila;
		cout << "indique posicion columna" << endl;
		cin >> posicionColumna;

		if (posicionFila > filas || posicionColumna > columnas)
		{
			cout << "la casilla se encuentra fuera de los limites del tateti, elija otra casilla" << endl;
		}

		else if (tableroTateti[posicionFila - 1][posicionColumna - 1] == "x" || tableroTateti[posicionFila - 1][posicionColumna - 1] == "o")
		{
			cout << "la casilla ya se encuentra ocupada, elija otra casilla" << endl;
		}

		else
		{
			if (numeroJugador == 1)
			{
				numeroJugador = 2;
				tableroTateti[posicionFila - 1][posicionColumna - 1] = "x";
				jugadasRealizadas++;
			}
			else
			{
				numeroJugador = 1;
				tableroTateti[posicionFila - 1][posicionColumna - 1] = "o";
				jugadasRealizadas++;
			}
		}

		tatetiDetectado = TatetiChecker(filas, columnas);

		if (tatetiDetectado == true || jugadasRealizadas == jugadasMaximas)
		{
			juegoTerminado = true;
		}
	}
	cout << "juego terminado! Presione cualquier tecla para jugar de nuevo, o ingrese N para finalizar" << endl;
	cin >> opcion;
	tatetiDetectado = false;
	juegoTerminado = false;
	jugadasRealizadas = 0;
	return opcion;
}
bool TatetiChecker(int filas, int columnas)
{
	bool tatetiScanner = false;
	string debugger;
	int limiteDiagonalderecha = columnas - 2;
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			bool tatetiVerticalX = j > 1 && (tableroTateti[i][j] == "x" && tableroTateti[i][j - 1] == "x" && tableroTateti[i][j - 2] == "x");
			bool tatetiVerticalO = j > 1 && (tableroTateti[i][j] == "o" && tableroTateti[i][j - 1] == "o" && tableroTateti[i][j - 2] == "o");
			bool tatetiHorizontalX = i > 1 && (tableroTateti[i][j] == "x" && tableroTateti[i - 1][j] == "x" && tableroTateti[i - 2][j] == "x");
			bool tatetiHorizontalO = i > 1 && (tableroTateti[i][j] == "o" && tableroTateti[i - 1][j] == "o" && tableroTateti[i - 2][j] == "o");
			bool tatetiDiagonalIzquierdaX = (i > 1 && j > 1) && (tableroTateti[i][j] == "x" && tableroTateti[i - 1][j - 1] == "x" && tableroTateti[i - 2][j - 2] == "x");
			bool tatetiDiagonalIzquierdaO = (i > 1 && j > 1) && (tableroTateti[i][j] == "o" && tableroTateti[i - 1][j - 1] == "o" && tableroTateti[i - 2][j - 2] == "o");
			bool tatetiDiagonalDerechaX = (i > 1 && j < limiteDiagonalderecha) && (tableroTateti[i][j] == "x" && tableroTateti[i - 1][j + 1] == "x" && tableroTateti[i - 2][j + 2] == "x");
			bool tatetiDiagonalDerechaO = (i > 1 && j < limiteDiagonalderecha) && (tableroTateti[i][j] == "o" && tableroTateti[i - 1][j + 1] == "o" && tableroTateti[i - 2][j + 2] == "o");

			cout << " | " << tableroTateti[i][j] << " | ";
			if (tatetiVerticalX || tatetiVerticalO || tatetiHorizontalX || tatetiHorizontalO || tatetiDiagonalIzquierdaX || tatetiDiagonalIzquierdaO || tatetiDiagonalDerechaX || tatetiDiagonalDerechaO)
			{
				tatetiScanner = true;
			}
		}
		cout << endl;
	}
	return tatetiScanner;
}
