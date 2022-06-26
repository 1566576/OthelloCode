#include <iostream>

void Create_Grid(char Grid[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Grid[i][j] = 254;
		}
	}
	Grid[3][3] = 2;
	Grid[3][4] = 1;
	Grid[4][3] = 1;
	Grid[4][4] = 2;
}
void Display_Grid(char Grid[][8])
{
	system("CLS");
	std::cout << "  ";
	for (int j = 0; j < 8; j++)
		std::cout << (char)(j + 97) << " ";
	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << (char)(i + 97) << " ";
		for (int j = 0; j < 8; j++)
		{
			std::cout << Grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Change_Sides(char Grid[][8], char x, char y, char player)
{
	int player2 = player % 2 + 1;
	int j,B, found,found2;
	//Check Right
	if (y+1 < 7 && Grid[x][y+1]==player2)
	{
		j = y + 1;
		while (Grid[x][j]==player2 && j <=7)
			j++;
		found = j;
		if (Grid[x][found]==player)
		{
			j = y + 1;
			while (j <= found)
			{
				Grid[x][j] = player; 
				j++;
			}
		}
	}
	//Check Left
	if (y-1 > 0 && Grid[x][y - 1] == player2)
	{
		j = y - 1;
		while (Grid[x][j] == player2 && j >= 0)
			j--;
		found = j;
		if (Grid[x][found] == player)
		{
			j = y - 1;
			while (j >= found)
			{
				Grid[x][j] = player;
				j--;
			}
		}
	}
	//Check Down
	if (x + 1 < 7 && Grid[x+1][y] == player2)
	{
		j = x + 1;
		while (Grid[j][y] == player2 && j <= 7)
			j++;
		found = j;
		if (Grid[found][y] == player)
		{
			j = x + 1;
			while (j <= found)
			{
				Grid[j][y] = player;
				j++;
			}
		}
	}
	//Check UP
	if (x - 1 > 0 && Grid[x - 1][y] == player2)
	{
		j = x - 1;
		while (Grid[j][y] == player2 && j >= 0)
			j--;
		found = j;
		if (Grid[found][y] == player)
		{
			j = x - 1;
			while (j >= found)
			{
				Grid[j][y] = player;
				j--;
			}
		}
	}
	//Check Up-Right
	if (x - 1 >0 && y+1<7 && Grid[x - 1][y+1] == player2)
	{
		j = x - 1;
		B = y + 1;
		while (Grid[j][B] == player2 && j >= 0 && B <= 7)
		{
			B++;
			j--;
		}
		found = j;
		found2 = B;
		if (Grid[found][found2] == player)
		{
			j = x - 1;
			B = y + 1;
			while (j >= found)
			{
				Grid[j][B] = player;
				j--;
				B++;
			}
		}
	}
	//Check Up-Left
	if (x - 1 > 0 && y - 1 > 0 && Grid[x - 1][y - 1] == player2)
	{
		j = x - 1;
		B = y - 1;
		while (Grid[j][B] == player2 && j >= 0 && B >= 0)
		{
			B--;
			j--;
		}
		found = j;
		found2 = B;
		if (Grid[found][found2] == player)
		{
			j = x - 1;
			B = y - 1;
			while (j >= found)
			{
				Grid[j][B] = player;
				j--;
				B--;
			}
		}
	}
	//Check Down-Right
	if (x + 1 < 7 && y + 1 < 7 && Grid[x + 1][y + 1] == player2)
	{
		j = x + 1;
		B = y + 1;
		while (Grid[j][B] == player2 && j <= 7 && B <= 7)
		{
			B++;
			j++;
		}
		found = j;
		found2 = B;
		if (Grid[found][found2] == player)
		{
			j = x + 1;
			B = y + 1;
			while (j <= found)
			{
				Grid[j][B] = player;
				j++;
				B++;
			}
		}
	}
	//Check Down-Left
	if (x + 1 < 7 && y - 1 > 0 && Grid[x + 1][y - 1] == player2)
	{
		j = x + 1;
		B = y - 1;
		while (Grid[j][B] == player2 && j <= 7 && B >= 0)
		{
			B--;
			j++;
		}
		found = j;
		found2 = B;
		if (Grid[found][found2] == player)
		{
			j = x + 1;
			B = y - 1;
			while (j <= found)
			{
				Grid[j][B] = player;
				j++;
				B--;
			}
		}
	}

}
bool Check_Position(char Grid[][8],char x,char y,char player)
{
	int z,k,d,A,iter;
	bool end = true;
	bool UpR = false;
	bool UpL = false;
	bool DwR = false;
	bool DwL = false;
	if (Grid[x][y]!=-2)
	{
		return false;
	}
	//Analisis de la existencia de fichas tuyas en tu fila y columna
	for (int i = 0; i < 8; i++)
	{
		if (Grid[x][i] == player)
		{
			i < y ? z = i : z = y; //minimo entre la ficha encontrada y la que ponemos
			z++;
			iter = z;
			for (;z < 8; z++)
			{
				if (z > iter &&((Grid[x][z] == player)||z==y))//Se puede poner la ficha, z debe ser mayor que i es decir +1 iteracion del for
					return true;
				if (Grid[x][z] != player % 2 + 1)//se ha interrumpido la conexion entre z e y
					break;
			}
		}
		if (Grid[i][y] == player)
		{
			i < x ? z = i : z = x; //minimo entre la ficha encontrada y la que ponemos
			z++;
			iter = z;
			for (; z < 8; z++)
			{
				if (z > iter &&((Grid[z][y] == player)||z==x))//Se puede poner la ficha, z debe ser mayor que i es decir +1 iteracion del for
					return true;
				if (Grid[z][y] != player % 2 + 1)//se ha interrumpido la conexion entre z e y
					break;
			}
		}
	}
	//Analisis de la existencia de fichas tuyas en tu las diagonales
	k = x;
	z = y;
	d = x;
	A = y;
	iter = 0;
	while(true)
	{
		k--;
		z--;
		d++;
		A++;
		if (d > 7 && A > 7 && k < 0 && z < 0)
			break;
		if (k >= 0 && z >= 0 && UpL==false)//hacia arriba izquierda - -
		{
			if (iter > 0 && Grid[k][z] == player)
				return true;
			if (Grid[k][z] != player % 2 + 1)//se ha interrumpido la conexion entre z e y
				UpL=true;
		}
		if (k >= 0 && A <= 7 && UpR==false)//hacia arriba derecha - +
		{
			if (iter > 0 && Grid[k][A] == player)
				return true;
			if (Grid[k][A] != player % 2 + 1)//se ha interrumpido la conexion entre z e y
				UpR = true;
		}
		if (d <= 7 && A <= 7 && DwR==false)//hacia abajo derecha + +
		{
			if (iter > 0 && Grid[d][A] == player)
				return true;
			if (Grid[d][A] != player % 2 + 1)//se ha interrumpido la conexion entre z e y
				DwR = true;
		}
		if (d <= 7 && z >= 0 && DwL==false)//hacia abajo izquierda + -
		{
			if (iter > 0 && Grid[d][z] == player)
				return true;
			if (Grid[d][z] != player % 2 + 1)//se ha interrumpido la conexion entre z e y
				DwL = true;
		}
		iter++;
	}
	return false;
}
void Player_Choice(char Grid[][8], char PlayerX)
{
	char x,y;
	std::cout << "Row = ";
	std::cin >> x;
	std::cout << "Column = ";
	std::cin >> y;
	while (!std::cin.good() || x < 97 || x >= (8 + 97) || y < 97 || y >= (8 + 97)|| !Check_Position(Grid,x-97,y-97,PlayerX))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("CLS");
		Display_Grid(Grid);
		std::cout << "Insert Correct data" << std::endl;
		std::cout << "Row = ";
		std::cin >> x;
		std::cout << "Column = ";
		std::cin >> y;
	}
	Change_Sides(Grid, x-97, y-97, PlayerX);
	Grid[x - 97][y - 97] = PlayerX;
}
bool Check_Win(char Grid[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
			if (Grid[i][j]==254)
			{
				return false;
			}
	}
	return true;
}

int main()
{
	char Grid[8][8];
	char Player=1;
	bool win = false;

	Create_Grid(Grid);
	Display_Grid(Grid);
	
	while (win==false)
	{
		Player_Choice(Grid, Player);

		Check_Win(Grid);
		
		Display_Grid(Grid);

		Player = Player % 2 + 1;
	}
	Player = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (Grid[i][j] == 1)
			{
				Player++;
			}
		}
	}
	if (Player>32)
	{
		std::cout << "Player 1 WON :" << Player << "-" << 64 - Player;
	}
	else
	{
		if (Player < 32)
		{
			std::cout << "Player 2 WON :" << Player-64 << "-" << Player;
		}
		else
			std::cout << "Tie :" << Player << "-" << 64 - Player;
	}
	return 0;
}