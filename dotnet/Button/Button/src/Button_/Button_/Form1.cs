using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Button_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // button1�̃e�L�X�g��ύX����.
            button1.Text = "button1 Clicked!";  // button1.Text��"button1 Clicked!"���Z�b�g.
        }
    }
}