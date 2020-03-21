using System;
namespace Backpack
{
    public class Item
    {
        public int cost { get; set; }
        public int weight { get; set; }
        public double value { get; set; }

        public Item(int Weight, int Cost)
        {
            cost = Cost;
            weight = Weight;

            value = (double)cost / weight;
        }
    }
}
