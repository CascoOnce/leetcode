// Problema: https://imgur.com/a/YkanSAr
// Solución Hash
// Entradas:
    /*
    Caso 1:
    [1,2,1]
    Caso 2: 
    [0,1,2,2]
    Caso 3:
    [1,2,3,2,2]
    */

var sol = new Solution();
int[] fruits1 = { 1, 2, 1, 2, 3 }, fruits2 = { 0, 1, 2, 2 };
int[] fruits3 = { 1, 2, 3, 2, 2 }, fruits4 = { 3,3,3,1,2,1,1,2,3,3,4 };
Console.WriteLine(sol.TotalFruit(fruits1));
Console.WriteLine(sol.TotalFruit(fruits2));
Console.WriteLine(sol.TotalFruit(fruits3));
Console.WriteLine(sol.TotalFruit(fruits4));

public class Solution
{
    public int TotalFruit(int[] fruits)
    {
        int left = 0, best = -1, size = fruits.Length;
        // Variables que usan el tipo de fruta
        int sum = 0;
        Dictionary<int, int> hash = new Dictionary<int, int>();
        for (int right = 0; right < size; right++)
        {
            int type = fruits[right];
            // No se encuentran en la canasta => Se agrega en el hash
            if (!hash.ContainsKey(type))
            {
                hash[type] = 0;
            }
            hash[type]++;
            sum++;

            if (hash.Count > 2)
            {
                while (hash.Count > 2)
                {
                    int actType = fruits[left];
                    hash[actType]--;
                    sum--;
                    left++;
                    if (hash[actType] == 0) hash.Remove(actType);
                }
            }

            best = Math.Max(best, sum);
        }
        return best;
    }
};