#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(int h, int l, double dens, int mode)
{
	board= new Board(h, l, dens, mode);	
}
Game::Game(string fileName, int mode)
{
	board= new Board(fileName, mode);
}
Game::~Game()
{
	delete board;
}
void Game::print()
{
	board->printBoard();
}
bool Game::check()
{
	//returns true if boards are not equal
	//used in program loop
	for (int i = 0; i < board->height; ++i)
		for (int j = 0; j < board->length; ++j)
			if (board->genInt[i][j]!=board->genNext[i][j])
				return true;
	return false;
}
void Game::simulate()
{
	//updates board then checks neighbors and uses count to modify board
	board->update();
	for (int i = 0; i<board->height; i++)
	{
		for (int j = 0; j<board->length; j++)
		{
			int nCount =0;
			if (board->getCell(i-1,j-1)=='X')
				nCount++;
			if (board->getCell(i-1,j)=='X')
				nCount++;
			if (board->getCell(i-1,j+1)=='X')
				nCount++;
			if (board->getCell(i,j-1)=='X')
				nCount++;
			if (board->getCell(i,j+1)=='X')
				nCount++;
			if (board->getCell(i+1,j-1)=='X')
				nCount++;
			if (board->getCell(i+1,j)=='X')
				nCount++;
			if (board->getCell(i+1,j+1)=='X')
				nCount++;

			if (nCount<=1)
				board->setCell(i,j,'-');
			else if (nCount==2)
				board->setCell(i,j,board->getCell(i,j));
			else if (nCount==3)
				board->setCell(i,j,'X');
			else if (nCount>=4)
				board->setCell(i,j,'-');
		}
	}
}
