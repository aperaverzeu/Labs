using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;

namespace UniProject.Utility
{
    class CreateADiploma
    {
        public static void AddTextToDiploma(Student student)
        {
            var img = Image.FromFile("template.jpg");
            var bitMapImage = (Bitmap)img;

            ImageCodecInfo myImageCodecInfo;
            System.Drawing.Imaging.Encoder myEncoder;
            EncoderParameter myEncoderParameter;
            EncoderParameters myEncoderParameters;

            System.Drawing.Image bitmap = (System.Drawing.Image)bitMapImage; // set image    
            Graphics graphicsImage = Graphics.FromImage(bitmap);

            //Set the alignment based on the coordinates      
            StringFormat stringformat = new StringFormat();
            stringformat.Alignment = StringAlignment.Far;
            stringformat.LineAlignment = StringAlignment.Far;

            StringFormat stringformat2 = new StringFormat();
            stringformat2.Alignment = StringAlignment.Center;
            stringformat2.LineAlignment = StringAlignment.Center;

            //Set the font color/format/size etc..     
            Color StringColor = System.Drawing.ColorTranslator.FromHtml("#535353");//direct color adding   
            Color StringColor2 = System.Drawing.ColorTranslator.FromHtml("#3E3E3E");//customise color adding   
            string Str_TextOnImage = student.University;
            string Str_TextOnImage1 = student.Faculty;
            string Str_TextOnImage2 = student.Name;
            string Str_TextOnImage3 = student.Surname;


            graphicsImage.DrawString(Str_TextOnImage, new Font("Times New Roman", 50,
                FontStyle.Regular), new SolidBrush(StringColor), new Point(500, 400),
                stringformat);

            graphicsImage.DrawString(Str_TextOnImage1, new Font("Times New Roman", 30,
                FontStyle.Regular), new SolidBrush(StringColor), new Point(400, 470),
                stringformat2);

            graphicsImage.DrawString(Str_TextOnImage2, new Font("Times New Roman", 70,
                FontStyle.Bold), new SolidBrush(StringColor2), new Point(400, 650),
                stringformat2);

            graphicsImage.DrawString(Str_TextOnImage3, new Font("Times New Roman", 70,
                FontStyle.Bold), new SolidBrush(StringColor2), new Point(400, 750),
                stringformat2);

            myImageCodecInfo = GetEncoderInfo("image/jpeg");
            myEncoder = System.Drawing.Imaging.Encoder.Quality;
            myEncoderParameters = new EncoderParameters(1);
            myEncoderParameter = new EncoderParameter(myEncoder, 75L);
            myEncoderParameters.Param[0] = myEncoderParameter;


            Console.WriteLine("Enter save path or leave empty to use default path (root of disk D):");
            string savePath = Console.ReadLine();
            savePath = savePath.Trim(' ');
            savePath = savePath.Trim('\"');
            if (savePath != "" && savePath.Last() != '\\')
            {
                savePath += "\\";
            }
            if (savePath.Length == 0)
            {
                try
                {
                    bitmap.Save(@"D:\Diploma.jpg", myImageCodecInfo, myEncoderParameters);
                    return;
                }
                catch (Exception)
                {
                    Console.WriteLine("Try again");
                }
            }
            try
            {
                bitmap.Save(savePath + "Diploma.jpg");
                return;
            }
            catch (Exception)
            {
                Console.WriteLine("Wrong path, try again");
            }
        }

        private static ImageCodecInfo GetEncoderInfo(String mimeType)
        {
            int j;
            ImageCodecInfo[] encoders;
            encoders = ImageCodecInfo.GetImageEncoders();
            for (j = 0; j < encoders.Length; ++j)
            {
                if (encoders[j].MimeType == mimeType)
                    return encoders[j];
            }
            return null;
        }
    }
}
