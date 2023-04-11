using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CUT3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private double L;
        private double n;
        private double Lambda;
        private double nHc;
        private double Alpha;
        private double npc;
        private double Pexit;
        private double Pfnp;
        private double deltaLambda;
        private double speedSTM4;
        private double tauSTM4;
        private double speedSTM16;
        private double tauSTM16;

        private const double AHc = 0.05;
        private const double Apc = 0.2;
        private const double Aeza = 3;
        private const double Aezk = 3;
        private const double LambdaMin = 1301.5;
        private const double LambdaMax = 1321.5;
        private const double S0 = 0.092;
        private const double D_PMD = 0.5;



        private void getvalues()
        {
            try
            {
                L = double.Parse(L_textBox1.Text);
                n = double.Parse(n_textBox2.Text);
                Lambda = double.Parse(Lambda_textBox3.Text) * Math.Pow(10,3);
                nHc = double.Parse(mufti_textBox4.Text);
                Alpha = double.Parse(alpha_textBox5.Text);
                npc = double.Parse(npc_textBox6.Text);
                Pexit = double.Parse(Pexit_textBox12.Text);
                Pfnp = double.Parse(Pfnp_textBox11.Text);
                deltaLambda = double.Parse(deltaLambda_textBox10.Text);
                speedSTM4 = double.Parse(SpeedSTM4_textBox9.Text);
                tauSTM4 = double.Parse(tauSTM4_textBox8.Text);
                speedSTM16 = double.Parse(speedSTM16_textBox7.Text);
                tauSTM16 = double.Parse(tauSTM16_textBox13.Text);
            }
            catch(Exception)
            {
                label14.Text = "Параметры введены неверно, применены значения по умолчанию";
                L = 50;
                n = 1.467;
                Lambda = 1.82*Math.Pow(10,3);
                nHc = 21;
                Alpha = 0.26;
                npc = 4;
                Pexit = 15;
                Pfnp = -20;
                deltaLambda = 0.02;
                speedSTM4 = 620;
                tauSTM4 = 420;
                speedSTM16 = 9900;
                tauSTM16 = 20;

            }


        }


        private void GetResult()
        {

            Polariz_Mode_Dispersion.Text = "Поляризационная модовая дисперсия: "+ Math.Round(Polarize_Mode_Dispersion(), 3).ToString();

            Chromatic_Dispesion.Text = "Хроматическая дисперсия: "+ Math.Round(chromaticDispersion(), 3).ToString();


            //Результирующее уширение импульса: 
            double resultingDispersion = Math.Sqrt(Math.Pow(chromaticDispersion(), 2) + Math.Pow(Polarize_Mode_Dispersion(), 2));

            Result_Width_Impulse.Text = "Результирующее уширение импульса: "+ Math.Round(resultingDispersion, 3).ToString();


            //битовый интервал 
            double bitInterval_STM_4 = 1 / speedSTM4;    
            double bitInterval_STM_16 = 1 / speedSTM16;


            //Максимально допустимая величина уширения импульсов 
            double maxAllowablePulseBroadeningValue_STM_4 = bitInterval_STM_4 / 2;   
            Max_STM4.Text = "Максимально допустимое уширение импульса STM-4: " + Math.Round(maxAllowablePulseBroadeningValue_STM_4, 6).ToString();

            double maxAllowablePulseBroadeningValue_STM_16 = bitInterval_STM_16 / 2;
            Max_STM16.Text = "Максимально допустимое уширение импульса STM-16: " + Math.Round(maxAllowablePulseBroadeningValue_STM_16, 6).ToString();

            //Начальная длительность импульсов 
            double initialPulseDuration_STM_4 = bitInterval_STM_4 / 4;     
            double initialPulseDuration_STM_16 = bitInterval_STM_16 / 4;


            //Конечная длительность импульса
            double finalPulseDuration_STM_4 = Final_Pulse_Duration(resultingDispersion, initialPulseDuration_STM_4);   
            Final_stm4.Text = "Конечная длительность для STM-4: " + Math.Round(finalPulseDuration_STM_4, 3).ToString();

            double finalPulseDuration_STM_16 = Final_Pulse_Duration(resultingDispersion, initialPulseDuration_STM_16);
            Final_stm16.Text = "Конечная длительность для STM-16: " + Math.Round(finalPulseDuration_STM_16, 3).ToString();
     
        }

        private double Final_Pulse_Duration(double resultingDispersion, double initial_pulse_duration)
        {
            return Math.Sqrt(Math.Pow(initial_pulse_duration, 2) + Math.Pow(resultingDispersion, 2));
        }


        private void GetBudget()
        {
            double A = AHc * nHc +  Alpha * L + Apc * npc;
            double budget = Pexit - Pfnp - Aeza - Aezk - A;
            energyb.Text = "Энергетический бюджет: " + budget.ToString();
            
        }


        private double Polarize_Mode_Dispersion()
        {
            return D_PMD * Math.Sqrt(L);
        }
        private double chromaticDispersion()
        {
            return (S0 *(Lambda - Math.Pow(LambdaMin, 4) / Math.Pow(Lambda, 3))/ 4) * deltaLambda * L;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            getvalues();
            GetResult();
            GetBudget();
        }
    }
}
