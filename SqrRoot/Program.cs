using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SqrRoot
{
    class Program
    {
        static void Main(string[] args)
        {
            var answer = SqrRoot(40);
            Console.WriteLine("SqrRoot(40) = {0}", answer);

            answer = SqrRoot(60);
            Console.WriteLine("SqrRoot(60) = {0}", answer);

            Console.WriteLine("Press any key to exit..."); 
            Console.ReadKey();
        }

        /// <summary>
        /// Evaluate the square root of n. 
        /// </summary>
        /// <param name="n">The lowest integer value that could be a square root of n.</param>
        /// <returns></returns>
        static int SqrRoot(int n)
        {
            if (n <= 0)
                return 0;

            int currentGuess = GetIntialGuess(n); 

            int previous = 0;

            while (currentGuess != previous)
            {
                previous = currentGuess;

                currentGuess = (previous + n / previous) / 2;
            }
            return currentGuess;



        }

        static int GetIntialGuess(int n)
        {
            int i = 0;

            while ((i * i) < n)
                i++;

            return i - 1; 
        }
    }
}
