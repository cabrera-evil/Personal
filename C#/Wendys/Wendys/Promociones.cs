using System;
using System.Windows.Forms;

namespace Wendys
{
    public partial class Promociones : Form
    {
        private double[] price = {16.99, 19.99, 12.99, 13.99, 18.99, 24.99, 11.55, 11.25};
        private double subTotal;
        public Promociones()
        {
            InitializeComponent();
        }

        private void btnCombos_Click(object sender, EventArgs e)
        {
            Combos combos = new Combos();
            combos.ShowDialog();
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

        private void btnComprar_Click(object sender, EventArgs e)
        {
            Pagar pagar = new Pagar();
            pagar.ShowDialog();
        }
    }
}