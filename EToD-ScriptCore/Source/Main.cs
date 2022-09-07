using System;
using System.Runtime.CompilerServices;

namespace ETOD
{
    public class Main
    {
        public float FloatVar { get; set; }

        public Main()
        {
            Console.WriteLine("Main constructor!");
            NativeLog("AAstroPhysic",8058);
        }

        public void PrintMessage()
        {
            Console.WriteLine("Hello World from EToD C# Engine!");
        }

        public void PrintInt(int value)
        {
            Console.WriteLine($"C# says: {value}");
        }

        public void PrintInts(int value1, int value2)
        {
            Console.WriteLine($"C# says: {value1} and {value2 }");
        }

        public void PrintCustomMessage(string message)
        {
            Console.WriteLine($"C# says: {message}");
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        extern static void NativeLog(string text, int parameter);
    }
}