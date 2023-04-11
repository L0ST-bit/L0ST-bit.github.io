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


namespace CUT4
{
    public partial class Form1 : Form
    {
        private double frequencyRange; 
        private static double L;
        private readonly int minHeight = 10, maxHeight = 100;

        List<double> k_FrenilZoneRelativeAntennaHeights = new List<double>();
        List<double> k_list = new List<double>();

        List<double> Earth = new List<double>();
        List<double> k_Earth = new List<double>();

        List<double> Height_ = new List<double>();
        List<double> x_ = new List<double>();

        public Form1()
        {
            InitializeComponent();
        }


        private void setValues()
        {
            try
            {
                L = double.Parse(lTextBox.Text) * 1e3;
                frequencyRange = double.Parse(frequencyRangeTextBox.Text) * 1e6;
            }
            catch(Exception)
            {
                L = 40 * 1e3;
                frequencyRange = 160 * 1e6;
            }


        }
        //Случайные значения для рельефа
        private List<int> getRandomDeltaHeightsList(List<int> deltaHeightsList, int minHeight, int maxHeight)
        {

            Random random = new Random();
            for (double i = 0; i <= 10; i++)
            {
                deltaHeightsList.Add(random.Next(minHeight, maxHeight));
            }

            return deltaHeightsList;
        }

        //Высоты рельефа
        private List<double> getRandomHeightsList(List<double> heightsList, List<double> earthsCurvatureList)
        {
            List<int> deltaHeightsList = new List<int>();
            deltaHeightsList = getRandomDeltaHeightsList(deltaHeightsList, minHeight, maxHeight);
            for (int i = 0; i <= 10; i++)
            {
                double x = i / 10d;
                double height = deltaHeightsList[i] + earthsCurvatureList[i];
                heightsList.Add(height);

                Height_.Add(height);
                
                x_.Add(x);
            }
            return heightsList;
        }

        //Рельеф поверхности
        private double getY(double k)
        {
            double R = 8500d * 1e3;

            double y = ((L * L) / (2 * R)) * k * (1 - k);
            return y;
        }

        //Кривизна земли
        private List<double> getEarthsCurvatureList(List<double> earthsCurvatureList)
        {
            for (double x = 0; x <= L; x += L / 10d)
            {
                double k = x / L;
                double y = getY(k);
                earthsCurvatureList.Add(y);
                Earth.Add(y);
                k_Earth.Add(k);
            }
            return earthsCurvatureList;
        }


        //Зона Френеля
        private List<double> getMinimumZone(List<double> FrenilZone, List<double> heightsList)
        {
            double c = 299792458;
            double Alpha = c / frequencyRange;
            for (double x = 0; x <= L; x += L / 10d)
            {
                double k = x / L;
                double xMinimumZone = Math.Sqrt((L * Alpha * k * (1 - k)) / 3d);
                FrenilZone.Add(xMinimumZone);
            }


            List<double> FrenilZoneRelativeAntennaHeights = new List<double>();

            for (double x = 0; x <= L; x += L / 10d)
            {
                double k = x / L;
                int i = (int)(10 * k);
                double xMinimumZoneRelativeAntennaHeights = heightsList.Max() - FrenilZone[i] + FrenilZone.Max() - FrenilZone.Min();
                FrenilZoneRelativeAntennaHeights.Add(xMinimumZoneRelativeAntennaHeights);
            }
            double minDistanceFrenilZoneToHeight = FrenilZoneRelativeAntennaHeights.First() - heightsList.First();
            double curDistance;
            for (int i = 0; i <= 10; i++)
            {
                curDistance = FrenilZoneRelativeAntennaHeights[i] - heightsList[i];
                if (curDistance < minDistanceFrenilZoneToHeight) minDistanceFrenilZoneToHeight = curDistance;
            }


            for (int i = 0; i < FrenilZoneRelativeAntennaHeights.Count; i++)
            {
                double k = i * 0.1;
                FrenilZoneRelativeAntennaHeights[i] -= minDistanceFrenilZoneToHeight;
                k_FrenilZoneRelativeAntennaHeights.Add(FrenilZoneRelativeAntennaHeights[i]);
                k_list.Add(k);

            }
            return FrenilZoneRelativeAntennaHeights;
        }



        private void button1_Click(object sender, EventArgs e)
        {
            k_FrenilZoneRelativeAntennaHeights.Clear();
            k_list.Clear();

            Earth.Clear();
            k_Earth.Clear();

            Height_.Clear();
            x_.Clear();



            setValues();
            firstAntennaHightLabel.Text = "Высота 1й мачты антенны: ";
            lastAntennaHightLabel.Text = "Высота 2й мачты антенны: ";

            List<double> earthsCurvatureList = new List<double>();
            earthsCurvatureList = getEarthsCurvatureList(earthsCurvatureList);


            List<double> heightsList = new List<double>();
            heightsList = getRandomHeightsList(heightsList, earthsCurvatureList);


            List<double> FrenilZone = new List<double>();

            FrenilZone = getMinimumZone(FrenilZone, heightsList);

            var plot = new ScottPlot.Plot(965, 680);
            plot.Style(Style.Gray1);
            plot.Palette = Palette.Category20;
            plot.Title("Профиль трассы РРЛ");
            plot.XLabel("k");
            plot.YLabel("h, м");

            double[] value = new double[] { 0, 1 };
            double[] value_min = new double[] { FrenilZone.First(), FrenilZone.Last() };

            plot.AddLine(0, FrenilZone.First(), 0, heightsList.First());
            plot.AddLine(1, FrenilZone.Last(), 1, heightsList.Last());
            plot.AddScatter(x_.ToArray(), Height_.ToArray(),color: Color.Aqua ,  label: "Высоты рельефа");
            plot.AddScatterLines(k_Earth.ToArray(), Earth.ToArray(), label: "Кривизна Земли");
            plot.AddScatterLines(k_list.ToArray(), k_FrenilZoneRelativeAntennaHeights.ToArray(), label: "Минимальная зона");
            plot.AddScatterLines(value, value_min, lineStyle: LineStyle.Dash, label:"Линия прямой видимости");
            plot.Legend();

            double firstAntennaHeight = Math.Ceiling(FrenilZone.First() - heightsList.First());
            double lastAntennaHeight = Math.Ceiling(FrenilZone.Last() - heightsList.Last());
            firstAntennaHightLabel.Text +=  firstAntennaHeight.ToString() + " м";
            lastAntennaHightLabel.Text += lastAntennaHeight.ToString() + " м";

            plot.SaveFig("1.png");
            pictureBox1.ImageLocation = "1.png";
        }
    }
}
