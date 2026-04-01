#include "MyForm.h"

TicTacToe::MyForm::MyForm(void) : turn(1) {
	InitializeComponent();
	Width = 300; 
	Height = 300; 
	turnLabel = gcnew Label();
	turnLabel->Location = Point(75, 10);
	turnLabel->Text = L"Ходит игрок" + (turn ? "X" : "O");
	Controls->Add(turnLabel);

	int x = 50, y = 50; 
	for (int i = 0; i < 9; ++i) {
		Button^ button = gcnew Button; 
		button->Width = 50;
		button->Height = 50;
		button->Location = Point(x, y); 
		button->Click += gcnew EventHandler(this, &MyForm::button_Click);
		Controls->Add(button); 
		buttons[i] = button;
		x += 50; 
		if (i + 1 % 3 == 0) {
			x = 50;
			y += 50; 

		}
	}
}

void TicTacToe::MyForm::button_Click(Object^ sender, EventArgs^ e)
{
	Button^ button = static_cast<Button^>(sender);
	if (button->Text == L"") {
		if (turn) button->Text = L"X";
		else button->Text = L"O";
		turn = 1 - turn; 
		checkWin(); 
	}
}

void TicTacToe::MyForm::clearGameField()
{
	for (int i = 0; i < 9; ++i)
		buttons[i]->Text = L"";
	turn = 1;
}

void TicTacToe::MyForm::checkWin()
{
	for (int i = 0; i < 3; ++i) {
		if (
			buttons[i]->Text != L"" &&
			buttons[i]->Text == buttons[i + 3]->Text &&
			buttons[i]->Text == buttons[i + 6]->Text
			) {
			MessageBox::Show("Игрок " + buttons[i]->Text + " выиграл!");
			clearGameField();
		} else if (
			buttons[i * 3]->Text != L"" &&
			buttons[i * 3] == buttons[i * 3 + 1] &&
			buttons[i * 3] == buttons[i * 3 + 2]
			) { 
			MessageBox::Show("Игрок " + buttons[i * 3]->Text + " выиграл!");
			clearGameField();
			}
	}
	if (
		buttons[0]->Text != L"" &&
		buttons[0]->Text == buttons[4]->Text &&
		buttons[0]->Text == buttons[8]->Text

		) {
		MessageBox::Show("Игрок " + buttons[0]->Text + " выиграл!");
		clearGameField();
	}
	if (
		buttons[2]->Text != L"" &&
		buttons[2]->Text == buttons[4]->Text &&
		buttons[2]->Text == buttons[6]->Text

		) {
		MessageBox::Show("Игрок " + buttons[2]->Text + " выиграл!");
		clearGameField();
	}
	bool is_draw = true; 
	for (int i = 0; i < 9; ++i)
		if (buttons[i]->Text == L"") is_draw = false; 
	if (is_draw) {
		MessageBox::Show("Игра закончилась ничьей");
		clearGameField();
	}
	turnLabel->Text = L"Ходит игрок " + (turn ? "X" : "O");

}
