using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Label
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // ���x���̃e�L�X�g��ύX����.
            label1.Text = "label1 Clicked!";    // label1.Text�̃e�L�X�g��"label1 Clicked!"�ɕύX.
        }
    }
}