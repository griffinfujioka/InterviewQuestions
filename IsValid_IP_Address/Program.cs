using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IsValid_IP_Address
{
    class Program
    {
        static void Main(string[] args)
        {
            ExecuteTestSuite();

            Console.Write("Press any key to exit...");
            Console.ReadKey(); 
        }

        /// <summary>
        /// Determine of the input string is a valid IP address.
        /// </summary>
        /// <param name="input"></param>
        /// <returns>Returns true if the input string is a valid input address, else returns false.</returns>
        static bool IsValidIPAddress(string input)
        {
            var segments = input.Split('.');

            // Check for the correct number of segments 
            if (segments.Length != 4)
                return false;

            foreach (string s in segments)
            {
                int intValueOfSegment = 0;

                if (!Int32.TryParse(s, out intValueOfSegment))
                    return false;       // The segment could not be represented as a 32-bit integer 

                if (intValueOfSegment < 0 || intValueOfSegment > 255)
                    return false;       // The value of the segment is invalid 
            }

            return true; 
        }

        static void ExecuteTestSuite()
        {
            Console.WriteLine("Test 1: 192.1"); 
            Console.WriteLine("Expected Result = FAIL");
            if (IsValidIPAddress("192.1"))
                Console.WriteLine("Actual Result: PASS");
            else
                Console.WriteLine("Actual Result: FAIL \nTest 1 passes");

            Console.WriteLine();


            Console.WriteLine("Test 2: 192.1.1.1.1.1.1");
            Console.WriteLine("Expected Result = FAIL");
            if (IsValidIPAddress("192.1.1.1.1.1.1"))
                Console.WriteLine("Actual Result: PASS");
            else
                Console.WriteLine("Actual Result: FAIL \nTest 2 passes");

            Console.WriteLine();


            Console.WriteLine("Test 3: 192.255.10.5");
            Console.WriteLine("Expected Result = PASS");
            if (IsValidIPAddress("192.255.10.5"))
                Console.WriteLine("Actual Result: PASS \nTest 3 passes");
            else
                Console.WriteLine("Actual Result: FAIL \nTest 3 fails");

            Console.WriteLine();


            Console.WriteLine("Test 4: a.b.c.d");
            Console.WriteLine("Expected Result = FAIL");
            if (IsValidIPAddress("a.b.c.d"))
                Console.WriteLine("Actual Result: PASS \nTest 4 fails");
            else
                Console.WriteLine("Actual Result: FAIL \nTest 4 passes");

            Console.WriteLine();


            Console.WriteLine("Test 5: 275.-5.10.5");
            Console.WriteLine("Expected Result = FAIL");
            if (IsValidIPAddress("275.-5.10.5"))
                Console.WriteLine("Actual Result: PASS \nTest 5 fails");
            else
                Console.WriteLine("Actual Result: FAIL \nTest 5 passes");
        }
    }
}
