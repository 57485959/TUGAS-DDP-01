#include <iostream>
using namespace std;

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};			// deklarasi array untuk papan permainan

void showtheboard(){							// fungsi untuk menampilkan papan permainan
  	cout << "              The option" << endl;
  	cout << "----------------------------------------" << endl;
    cout << " 1 | 2 | 3 " << endl;
    cout << "-----------" << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "-----------" << endl;
    cout << " 7 | 8 | 9 " << endl;
    cout << "----------------- Start ----------------" << endl;
  	cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
  	cout << "---|---|---" << endl;
  	cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
  	cout << "---|---|---" << endl;
 	cout << " " << board[2][0] << " | " << board[2][1] << " | "<< board[2][2] << endl;
}

char checkthewinner(){							// fungsi untuk memeriksa pemenang atau seri
    for (int w = 0; w < 3; w++){	
        if (board[w][0] == board[w][1] && board[w][1] == board[w][2] && board[w][0] != ' '){
            return board[w][0];
        } if (board[0][w] == board[1][w] && board[1][w] == board[2][w] && board[0][w] != ' '){
            return board[0][w];
        } if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' '){
        	return board[0][0];
    	} if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '){
        	return board[0][2];
    	}
	}
	
    bool boardfull = true;					// cek seri
    for (int w = 0; w < 3; w++){
        for (int h = 0; h < 3; h++){
            if (board[w][h] == ' '){
                boardfull = false;
                break;
            }
        }
    }
    if (boardfull){
        return 'D';
    }
    return ' ';									// cek belum ada pemenang atau seri
}

int input(){									// fungsi untuk mengambil input dari pemain
    int choice;
    cout << "Enter the number from the box : ";
    cin >> choice;
    cout << "-------------- next player -------------" << endl;
    cout << endl;
    cout << "----------------------------------------" << endl;
    while (choice < 1 || choice > 9 || board[(choice-1)/3][(choice-1)%3] != ' '){			// validasi/pengecekan input
    	cout << "Invalid input. Please enter the number in the blank box between 1 and 9: ";
        cin >> choice;
        cout << endl;
    }
    return choice;
}

void markboard(int choice, char symbol){		// fungsi untuk mengganti isi array dengan simbol pemain
    board[(choice-1)/3][(choice-1)%3] = symbol;
}

int main(){										// sebagai fungsi utama untuk menjalankan permainan
    bool isXturn = true; 				// variabel untuk menentukan giliran pemain
    bool isGameOver = false; 			// variabel untuk menentukan status permainan
    char winner; 						// variabel untuk menyimpan simbol pemenang
    char again; 						// variabel untuk menyimpan pilihan bermain lagi

  	cout << "----------------------------------------" << endl;
  	cout << "      Welcome to Tic Toc Toe Game!" << endl;
  	cout << "----------------------------------------" << endl;
  	
    do{
    	showtheboard(); 				// menampilkan papan permainan
        int choice = input();			// mengambil input dari pemain
        if (isXturn){
            markboard(choice, 'X'); 	// menandai papan dengan simbol X
            isXturn = false; 			// mengganti giliran pemain ke dua, dengan simbol O
        } else {
            markboard(choice, 'O'); 	// menandai papan dengan simbol O
            isXturn = true; 			// mengganti giliran pemain pertama, dengan simbol X
        }

        winner = checkthewinner(); 		// memeriksa pemenang atau seri
        if (winner != ' '){
            showtheboard(); 			// menampilkan papan permainan terakhir
            if (winner == 'D'){
              	cout << "----------------------------------------" << endl;
                cout << "This game is a draw!" << endl;
                cout << "----------------------------------------" << endl;
            } else{
              	cout << "----------------------------------------" << endl;
                cout << "The winner is " << winner << "!" << endl;
                cout << "----------------------------------------" << endl;
            }
            cout << "Do you want to play again? (Y/N): "; // menawarkan pilihan bermain lagi
            cin >> again;
            cout << "----------------------------------------" << endl;
            if (again == 'Y' || again == 'y'){
                isGameOver = false; 					// jika memulai permainan kembali
                isXturn = true; 						// mengembalikan giliran ke pemain X
                for (int w = 0; w < 3; w++){			// mengosongkan papan permainan
                    for (int h = 0; h < 3; h++){
                        board[w][h] = ' ';
                    }
                }
            } else {
            	isGameOver = true;
            	cout << "Close the program...." << endl;
			}
        }
    } while (!isGameOver); 		// mengulang permainan sampai ada pemenang atau seri
    return 0;
}

