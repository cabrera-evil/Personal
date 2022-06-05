using System;
using System.Windows.Forms;

namespace Wendys
{
    public partial class Pagar : Form
    {
        public Pagar()
        {
            InitializeComponent();
        }

        private void lstProducts_SelectedIndexChanged(object sender, EventArgs e)
        {
            Promociones promociones = new Promociones();
            Combos combos = new Combos();
        }
    }
}