using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SudokuSolver
{
	class Program
	{
		static void Main(string[] args)
		{
			int[,] grid = new int[9, 9]  { { 0, 9, 0, 0, 0, 0, 8, 5, 3 },
										   { 0, 0, 0, 8, 0, 0, 0, 0, 4 },
										   { 0, 0, 8, 2, 0, 3, 0, 6, 9 },
										   { 5, 7, 4, 0, 0, 2, 0, 0, 0 },
										   { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
										   { 0, 0, 0, 9, 0, 0, 6, 3, 7 },
										   { 9, 4, 0, 1, 0, 8, 5, 0, 0 },
										   { 7, 0, 0, 0, 0, 6, 0, 0, 0 },
										   { 6, 8, 2, 0, 0, 0, 0, 9, 0 } };

			Sudoku sudoku = new Sudoku(grid);
			Sudoku.print_grid(sudoku.grid);

			if (Sudoku.solve_soduko(sudoku.grid) == true)
			{
				Sudoku.print_grid(sudoku.grid);
			}

			Console.ReadKey();
		}
	}
}
