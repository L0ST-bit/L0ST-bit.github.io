using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using ScottPlot;

namespace CUT2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private double L, Kl, Kc, Ko;

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            getValues();


            


            List<double> NN = new List<double>();

            List<double> N_K1 = new List<double>();
            List<double> N_K2 = new List<double>();
            List<double> d_K = new List<double>();

            List<double> N_k1 = new List<double>();
            List<double> N_k2 = new List<double>();
            List<double> d_k = new List<double>();

            int iN = 0;
            int borderN = 0;
            //Общее капитальное вложение
            N_K1.Add((Kl + 0 * Kc) * L);
            N_K2.Add((Kl + Kc) * L + 2 * Ko);

            N_k1.Add(0);
            N_k2.Add(0);

            d_k.Add(0);
            d_K.Add(0);

            do
            {
                iN++;

                N_K1.Add((Kl + iN * Kc) * L);
                N_K2.Add(N_K2[0]);

                //Удельные капитальные вложения
                N_k1.Add(N_K1[iN] / (iN * L));
                N_k2.Add(N_K2[iN] / (iN * L));


                //общая экономия
                d_K.Add(N_K1[iN] - N_K2[iN]);

                //Удельная экономия
                d_k.Add(d_K[iN] / (iN * L));

                NN.Add(iN);
                //Граничная N
                if (d_k[iN] <= 0 && d_K[iN] <= 0)
                {
                    borderN = iN+1;
                }

            } while (d_k[iN] <= 0 && d_K[iN] <= 0);

            //Ниже вывод значений построение графиков
            label1.Text = "Граничная N = " + borderN.ToString();
            NN.Add(iN+1);
            var plot = new ScottPlot.Plot(865, 580);
            plot.Style(Style.Gray1);
            plot.Palette = Palette.Category20;
            plot.XLabel("N");
            plot.YLabel("K");

            var plot1 = new ScottPlot.Plot(865, 580);
            plot1.Style(Style.Gray1);
            plot1.Palette = Palette.Category20;
            plot1.XLabel("N");
            plot1.YLabel("k");

            plot.AddScatterLines(NN.ToArray(), N_K1.ToArray(), label: "Single K");
            plot.AddScatterLines(NN.ToArray(), N_K2.ToArray(), label: "Multiple K");

            NN.RemoveAt(0); d_k.RemoveAt(0); d_K.RemoveAt(0); N_k1.RemoveAt(0); N_k2.RemoveAt(0);
            plot.AddScatterLines(NN.ToArray(), d_K.ToArray(), label: "dK");
            plot.Legend();
            plot1.AddScatterLines(NN.ToArray(), N_k1.ToArray(), label: "Single k");
            plot1.AddScatterLines(NN.ToArray(), N_k2.ToArray(), label: "Multiple k");
            plot1.AddScatterLines(NN.ToArray(), d_k.ToArray(), label: "dK");
            plot1.Legend();

            

            plot.SaveFig("1.png");
            pictureBox1.ImageLocation = "1.png";
            plot1.SaveFig("2.png");
            pictureBox2.ImageLocation = "2.png";

        }

        private void getValues()
        {
            try
            {
                L = double.Parse(textBox1.Text);
                Kl = double.Parse(textBox2.Text);
                Kc = double.Parse(textBox3.Text);
                Ko = double.Parse(textBox4.Text);
               
            }
            catch(Exception)
            {
                L = 100;
                Kl = 2000;
                Kc = 3000;
                Ko = 50000;
                label6.Text = "Введены параметры по умолчанию";
               
            }
        }


    }

}
