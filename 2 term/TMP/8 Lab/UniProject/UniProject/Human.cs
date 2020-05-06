using System;
using System.ComponentModel.DataAnnotations;
namespace UniProject
{
    public class Human : IEquatable<Human>
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        public int Age { get; set; }
        public Gender Gender { get; set; }
        public string Country { get; set; }
        public Race Race { get; set; }
        public double Weight { get; set; }
        public int Height { get; set; }
        public Guid PassportNumber { get; private set; }


        public Human(string name, string surname, int age)
        {
            Name = name;
            Surname = surname;
            Age = age;
            Gender = Gender.Other;
            Country = "Belarus";
            Race = Race.White;
            Weight = 70.0;
            Height = 175;
            PassportNumber = GivePassportNumber();
        }

        private Guid GivePassportNumber()
        {
            return Guid.NewGuid();
        }

        public Human(string name, string surname, int age, Gender gender, string country, Race race, double weight, int height)
        {
            Name = name;
            Surname = surname;
            Age = age;
            Gender = gender;
            Country = country;
            Race = race;
            Weight = weight;
            Height = height;
            PassportNumber = GivePassportNumber();
        }

        public override string ToString()
        {
            return "Person: " + Name + "\t" + Surname + "\t" + Age + "\n" +
                   "        " + Country + "\t" + Gender + "\t" + Race + "\n" +
                   "        " + Weight + "\t" + Height + "\t" + PassportNumber + "\n";
        }

        public double BMICalculate()
        {
            return Weight / (Height * Height) * 10000;
        }

        public bool Equals(Human other)
        {
            if (other == null)
                return false;

            return this.PassportNumber.Equals(other.PassportNumber);
        }
    }
}
