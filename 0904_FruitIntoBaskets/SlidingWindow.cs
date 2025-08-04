// Problema: https://imgur.com/a/YkanSAr
// Solución Sliding Window
// Entradas:
    /*
    Caso 1:
    [1,2,1]
    Caso 2: 
    [0,1,2,2]
    Caso 3:
    [1,2,3,2,2]
    */

using System;


var sol = new Solution();
int[] fruits1 = { 1, 2, 1, 2, 3 };
int[] fruits2 = { 0, 1, 2, 2 };
int[] fruits3 = { 1, 2, 3, 2, 2 };
int[] fruits4 = { 3,3,3,1,2,1,1,2,3,3,4 };
Console.WriteLine(sol.TotalFruit(fruits1));
Console.WriteLine(sol.TotalFruit(fruits2));
Console.WriteLine(sol.TotalFruit(fruits3));
Console.WriteLine(sol.TotalFruit(fruits4));
// Console.WriteLine("Hola, mundo!");

public class Solution
{
    public int TotalFruit(int[] fruits)
    {
        int left = 0, best = -1, size = fruits.Length;
        // Variables que usan el tipo de fruta
        int basket1 = -1, basket2 = -1;
        for (int right = 0; right < size; right++)
        {
            if (fruits[right] != basket1 && fruits[right] != basket2)
            {
                if (basket1 == -1) basket1 = fruits[right];
                else if (basket2 == -1) basket2 = fruits[right];
                else
                {
                    basket1 = fruits[right];
                    basket2 = fruits[right - 1];
                    left = right - 1;
                    while (fruits[left - 1] == basket2) left--;
                }
            }
            best = Math.Max(best, right - left + 1);
        }
        // Console.WriteLine();
        return best;
    }
};