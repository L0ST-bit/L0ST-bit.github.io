using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ScottPlot;

namespace CUT1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }



        private void button1_Click(object sender, EventArgs e)
        {
            double Pexit = -8;
            double A = 4;
            double Pnom = -24;
            double Snp = 5;
            double S = 21;
            double alpha;

            if(!double.TryParse(textBox1.Text, out alpha))
            {
                alpha = 1.0;
                textBox1.Text = "1,0";
            }
            double L;
            if (!double.TryParse(textBox2.Text, out L))
            {
                L = 100;
                textBox2.Text = "100";
            }
            //double L = double.Parse(textBox2.Text);
            double Snep = 19;
            double Pbx = -8.0;
            

            

            var plot = new ScottPlot.Plot(765, 530);
            plot.Style(Style.Gray1);
            plot.Palette = Palette.Category20;
            plot.Title("Диаграмма уровней");
            plot.XLabel("L");
            plot.YLabel("S");

            List<double> SignalY = new List<double>();
            List<double> stepX = new List<double>();
            List<double> pA = new List<double>();
            List<double> PnomX = new List<double>();

            Pbx += Snep;
            
            SignalY.Add(Pbx);
            stepX.Add(0);
            pA.Add(Pnom + A);
            PnomX.Add(Pnom);
            double shag = 0.01;
            double Accur = alpha *shag;

            for (double i = 1; i < L+shag; i+=shag)
            {
                Pbx -=Accur;

                SignalY.Add(Pbx);
                stepX.Add(i);

                pA.Add(Pnom + A);
                PnomX.Add(Pnom);

                if (Pbx - Accur < Pnom + A)
                {
                    Pbx += S;
                    
                }
                if ((i+shag) > L)
                {
                    Pbx += Snp;
                }
                if ((Pbx - Accur) < Pexit && (i + shag) > L)
                {
                    Pbx += (Pexit - Pbx);

                }
            }
            
            double[] Signal = new double[SignalY.Count];
            double[] step = new double[stepX.Count];
            double[] Aa = new double[stepX.Count];
            double[] PnomY = new double[stepX.Count];

            for (int k = 0; k < step.Length; k++)
            {
                Signal[k] = SignalY[k];
                step[k] = stepX[k];
                Aa[k] = pA[k];
                PnomY[k] = PnomX[k];
            }
            plot.AddScatterLines(step, Signal, label: "Уровень сигнала");
            plot.AddScatterLines(step, Aa, label: "Линия защищенности");
            plot.AddScatterLines(step, PnomY, label:"Уровень помех", lineStyle: LineStyle.DashDot);
            plot.Legend();
            
            plot.SaveFig("1.png");
            pictureBox1.ImageLocation = "1.png";

        }
    }
}
