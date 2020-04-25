using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace SudokuSolver
{
    class Sudoku
    {
        public int[,] grid { get; set; }

        [DllImport("SudokuCore.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern void print_grid(int[,] grid);

        [DllImport("SudokuCore.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern bool solve_soduko(int[,] grid);

        public Sudoku()
        {
            grid = new int[9, 9];
            full_new_grid();
        }

        public Sudoku(int[,] grid)
        {
            if ((grid.GetLength(0) == 9) && grid.GetLength(1) == 9)
            {
                this.grid = grid;
            }
            else
            {
                this.grid = new int[9, 9];
                full_new_grid();
            }
            
        }

        public void full_new_grid()
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    grid[i, j] = 0;
                }
            }
        }

        public void set_grid()
        {
            Console.WriteLine("Enter your doard form upper left corner to botttom right. 0 - blank sell.");
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    grid[i, j] = Convert.ToInt32(Console.ReadLine());
                }
            }
        }
    }
}
