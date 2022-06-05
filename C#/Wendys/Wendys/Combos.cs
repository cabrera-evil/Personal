using System;
using System.Windows.Forms;

namespace Wendys
{
    public partial class Combos : Form
    {
        private double[] price = {6.90, 7.90, 8.90, 8.70, 7.50, 8.70, 8.70, 7.50};
        private double subTotal;
        
        public Combos()
        {
            InitializeComponent();
        }

        private void btnPrice1_Click(object sender, EventArgs e)
        {
            subTotal += price[0];
            lblTotal.Text = "Total: $" + Math.Round(subTotal, 2);
        }

        private void lblPrice2_Click(object sender, EventArgs e)
        {
            subTotal += price[1];
            lblTotal.Text = "Total: $" + Math.Round(subTotal, 2);
        }

        private void btnPrice3_Click(object sender, EventArgs e)
        {
            subTotal += price[2];
            lblTotal.Text = "Total: $" + Math.Round(subTotal, 2);
        }

        private void btnPrice4_Click(object sender, EventArgs e)
        {
            subTotal += price[3];
            lblTotal.Text = "Total: $" + Math.Round(subTotal, 2);
        }

        private void btnPrice5_Click(object sender, EventArgs e)
        {
            subTotal += price[4];
            lblTotal.Text = "Total: $" + Math.Round(subTotal, 2);
        }

        private void btnPrice6_Click(object sender, EventArgs e)
        {
            subTotal += price[5];
            lblTotal.Text = "Total: $" + Math.Round(subTotal, 2);
        }

        private void btnPrice7_Click(object sender, EventArgs e)
        {
            subTotal += price[6];
            lblTotal.Text = "Total: $" + Math.Round(subTotal, 2);
        }

        private void btnPrice8_Click(object sender, EventArgs e)
        {
            subTotal += price[7];
            lblTotal.Text = "Total: $" + Math.Round(subTotal, 2);
        }
    }
}