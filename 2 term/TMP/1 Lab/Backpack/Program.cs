using System;
using System.Collections.Generic;
using System.Linq;

namespace Backpack
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Initial data:");

            InputFromFile inputFrom = new InputFromFile(@"/Users/Alex/Documents/Education/Labs/2 term/ИСП/first/Backpack/Backpack/inputVolume.txt",
                                                        @"/Users/Alex/Documents/Education/Labs/2 term/ИСП/first/Backpack/Backpack/input.txt");

            int capacity = inputFrom.readVolume();
            Console.WriteLine("Capacity of a backpack:\t {0}\n", capacity);

            Console.WriteLine("Our data: ");
            List<Item> items = inputFrom.readItems();

            foreach (var item in items)
            {
                Console.WriteLine("Weight:\t {0}\t Cost:\t {1}\t Value:\t {2}", item.weight, item.cost, item.value);
            }
            Console.WriteLine();

            Console.WriteLine("Sorted items: ");
            items = items.OrderByDescending(p => p.value).ThenBy(p => p.weight).ToList<Item>();

            foreach (var item in items)
            {
                Console.WriteLine("Weight:\t {0}\t Cost:\t {1}\t Value:\t {2}", item.weight, item.cost, item.value);
            }

            int currentVolume = 0;
            int finalCost = 0;

            for (int i = 0; i < items.Count; i++)
            {
                if (currentVolume + items[i].weight <= capacity)
                {
                    currentVolume += items[i].weight;
                    finalCost += items[i].cost;
                }
            }
            Console.WriteLine("\nResults of our research:");
            Console.WriteLine("Final cost of the backpack: {0}", finalCost);
            Console.WriteLine($"Final volume of items: {currentVolume}");
        }
    }
}
