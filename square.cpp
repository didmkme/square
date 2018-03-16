#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	fstream datafile, file;
	datafile.open ("input.txt", ios::out | ios::in);
	file.open("output.txt", ios::out);

	if (!datafile)
		cout << "Error opening file." << endl;
	else
		cout << "The datafile was opened." << endl;

	if (!file)
		cout << "Error opening file." << endl;
	else
		cout << "The file was opened." << endl;
		
	int n, m, h[10][10], v[10][10];

	datafile >> n; 
	cout << n << endl;
	if (2 > n || n > 9)
	{
		cout << n << endl;
		cout << "Error! Number of dots should be between 1 and 10." << " " << "Please fix it" << endl;
		system("pause");
		exit(0);
	}
	
	datafile >> m;
	cout << m << endl;
	if (m > 2 * (n*n - n) || m < 0)
	{
		cout << m << endl;
		cout << "Error! Number of lines should be between 0 and " << 2 * (n*n- n) << " " << "Please fix it." << endl;
		system("pause");
		exit(0);
	}
		char ch;
		int row, col;
		while (!datafile.eof())
		{
			datafile >> ch;
			datafile >> row;
			if (row > n)
			{
				cout << "Error! Line numbers should be less than dot number ." << endl;
				system("pause");
				exit(0);
			}
			datafile >> col;
			if (col > n)
			{
				cout << "Error! Line numbers should be less than dot number ." << endl;
				system("pause");
				exit(0);
			}
			cout << ch;
			cout << " " << row;
			cout << " " << col;
			if (ch == 'H' || ch == 'h')
				h[row][col] = 1;
			if (ch == 'V' || ch == 'v')
				v[row][col] = 1;
			cout << endl;
		}
		int sayac = 0, sayac2 = 0, sayac3 = 0, sayac4 = 0, sayac5 = 0, sayac6 = 0, sayac7 = 0, sayac8 = 0;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (h[i][j] == 1 && v[j][i] == 1)
			{
				if (h[i + 1][j] == 1 && v[j + 1][i] == 1)
					sayac++;
				if (h[i][j+1] == 1 && v[j][i+1] == 1)
				{
					if(h[i + 2][j + 1] == 1 && v[j + 2][i + 1] == 1&& h[i + 2][j] == 1 && v[j + 2][i] == 1)
						sayac2++;
					if (h[i][j + 2] == 1 && v[j][i + 2] == 1)
					{
						if (h[i + 3][j] == 1 && h[i + 3][j + 1] == 1 && h[i + 3][j + 2] == 1 && v[j + 3][i] == 1 && v[j + 3][i + 1] == 1 && v[j + 3][i + 2] == 1)
							sayac3++;
						if (h[i][j + 3] == 1 && v[j][i + 3] == 1)
						{
							if (h[i + 4][j] == 1 && h[i + 4][j + 1] == 1 && h[i + 4][j + 2] == 1 && h[i + 4][j + 3] == 1 && v[j + 4][i] == 1 && v[j + 4][i + 1] == 1 && v[j + 4][i + 2] == 1 && v[j + 4][i + 3])
								sayac4++;
							if (h[i][j + 4] == 1 && v[j][i + 4] == 1)
							{
								if (h[i + 5][j] == 1 && h[i + 5][j + 1] == 1 && h[i + 5][j + 2] == 1 && h[i + 5][j + 3] == 1 && h[i + 5][j + 4] == 1 &&v[j + 5][i] == 1 && v[j + 5][i + 1] == 1 && v[j + 5][i + 2] == 1 && v[j + 5][i + 3] == 1 && v[i + 5][j + 4] == 1)
									sayac5++;
								if (h[i][j + 5] == 1 && v[j][i + 5] == 1)
								{
									if (h[i + 6][j] == 1 && h[i + 6][j + 1] == 1 && h[i + 6][j + 2] == 1 && h[i + 6][j + 3] == 1 && h[i + 6][j + 4] == 1 && v[j + 6][i] == 1 && v[j + 6][i + 1] == 1 && v[j + 6][i + 2] == 1 && v[j + 6][i + 3] == 1 && v[i + 6][j + 4] == 1)
										sayac6++;
								}
								if (h[i][j + 6] == 1 && v[j][i + 6] == 1)
								{
									if (h[i + 7][j] == 1 && h[i + 7][j + 1] == 1 && h[i + 7][j + 2] == 1 && h[i + 7][j + 3] == 1 && h[i + 7][j + 4] == 1 && v[j + 7][i] == 1 && v[j + 7][i + 1] == 1 && v[j + 7][i + 2] == 1 && v[j + 7][i + 3] == 1 && v[i + 7][j + 4] == 1)
										sayac7++;
									if (h[i][j + 7] == 1 && v[j][i + 7] == 1)
									{
										if (h[i + 8][j] == 1 && h[i + 8][j + 1] == 1 && h[i + 8][j + 2] == 1 && h[i + 8][j + 3] == 1 && h[i + 8][j + 4] == 1 && v[j + 8][i] == 1 && v[j + 8][i + 1] == 1 && v[j + 8][i + 2] == 1 && v[j + 8][i + 3] == 1 && v[i + 8][j + 4] == 1)
											sayac8++;
									}

								}
							}
						}
					}
				}
			}
		}				
	}
	if (sayac == 0 && sayac2 == 0 && sayac3 == 0 && sayac4 == 0 && sayac5 == 0 && sayac6 == 0 && sayac7 == 0 && sayac8 == 0 )
	{
		cout << "No completed squares can be found." << endl;
		file << "No completed squares can be found.";
	}
	if (sayac != 0)
	{
		cout << sayac << " square(s) size of 1" << endl;
		file << sayac << " square(s) size of 1" << endl;

	}
	if (sayac2 != 0)
	{
		cout << sayac2 << " square(s) size of 2" << endl;
		file << sayac2 << " square(s) size of 2" << endl;

	}
	if (sayac3 != 0)
	{
		cout << sayac3 << " square(s) size of 3" << endl;
		file << sayac3 << " square(s) size of 3" << endl;

	}
	if (sayac4 != 0)
	{
		cout << sayac4 << " square(s) size of 4" << endl;
		file << sayac4 << " square(s) size of 4" << endl;

	}
	if (sayac5 != 0)
	{
		cout << sayac5 << " square(s) size of 5" << endl;
		file << sayac5 << " square(s) size of 5" << endl;

	}
	if (sayac6 != 0)
	{
		cout << sayac6 << " square(s) size of 6" << endl;
		file << sayac6 << " square(s) size of 6" << endl;

	}
	if (sayac7 != 0)
	{
		cout << sayac7 << " square(s) size of 7" << endl;
		file << sayac7 << " square(s) size of 7" << endl;

	}
	if (sayac8 != 0)
	{
		cout << sayac8 << " square(s) size of 8" << endl;
		file << sayac8 << " square(s) size of 8" << endl;

	}
	        datafile.close();
	        file.close();
	        system("pause");
}