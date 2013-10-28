using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cobalt_Intervie2
{
    class Program
    {
        public static Dictionary<string, int> GroupWords(string input)
        {
            if (input == null)
                return null; 

            var returnDictionary = new Dictionary<string, int>();

            var words = input.Split(',');


            foreach (string s in words)
            {
                if (returnDictionary.ContainsKey(s))
                {
                    returnDictionary[s]++;      // increment the value
                }
                else
                {
                    // The word is not in the dictionary, insert it 
                    returnDictionary.Add(s, 1); 
                }
            }

            return returnDictionary; 
        }

        static void ExecuteTestSuite()
        {
            var s = "Cobalt,Griffin,Cobalt,ADP,Ravi,Ravi,Ravi,Cobalt";
            Console.WriteLine("Test 1: {0}", s);
            var dict = GroupWords(s);
            PrintDictionary(dict);

            s = "";                             // Test the empty input 
            Console.WriteLine("Test 2: {0}", s);
            dict = GroupWords(s);
            PrintDictionary(dict);

            s = "Cobalt Cobalt Cobalt";         // Not going to work because delimiters are different 
            Console.WriteLine("Test 3: {0}", s);
            dict = GroupWords(s);
            PrintDictionary(dict);

            s = "CobaltCobaltCobalt";           // Not going to work because no delimiters are present 
            Console.WriteLine("Test 4: {0}", s);
            dict = GroupWords(s);
            PrintDictionary(dict);

            s = "Griffin,,Griffin,Griffin";      // Expect it to insert an empty string as a key for the dictionary 
            Console.WriteLine("Test 5: {0}", s);
            dict = GroupWords(s);
            PrintDictionary(dict);

            s = null;                           // What happens if I pass in null?
            Console.WriteLine("Test 6: {0}", s);
            dict = GroupWords(s);
            PrintDictionary(dict);

            


        }

        static void PrintDictionary(Dictionary<string, int> dict)
        {
            int e;

            if (dict == null)
                return;


            foreach(string key in dict.Keys)
            {
                Console.WriteLine("{0} : {1}", key, dict[key]); 
            }
        }


        static void Main(string[] args)
        {
            ExecuteTestSuite();

            // While there are chunks left to be read, read the biggest chunk from the file that I can 
            // 

            // Issue: What happens if the dictionary becomes too large and I run out of memory? 
            

            // How to make sure the program is extendible and able to "plug and play" 



            Console.WriteLine("Press any key to exit...");
            Console.ReadKey(); 
        }
    }


}
