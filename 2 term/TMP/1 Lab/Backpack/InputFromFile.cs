using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Backpack
{
    public class InputFromFile
    {
        public InputFromFile(string VolumePath, string ItemsPath)
        {
            volumePath = VolumePath;
            itemsPath = ItemsPath;
        }

        private string volumePath { get; set; }
        private string itemsPath { get; set; }

        public int readVolume()
        {
            return Convert.ToInt32(File.ReadLines(volumePath).First());
        }

        public List<Item> readItems()
        {
            List<Item> items = new List<Item>();

            StreamReader sr = new StreamReader(itemsPath);

            while (!sr.EndOfStream)
            {
                string parameters = sr.ReadLine();

                string[] parms = parameters.Split(new char[] { ' ' });

                Item item = new Item(Convert.ToInt32(parms[0]), Convert.ToInt32(parms[1]));

                items.Add(item);
            }

            return items;
        }
    }
}
