using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Form_
{
    public partial class Form1 : Form
    {
        public int i;   // int�^�ϐ�i.
        public Form1()
        {
            i = 0;  // i��0�ŏ�����.
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            i++;    // i��1���₷.
            label2.Text = i.ToString(); // label2��i.ToString���Z�b�g.
        }

        private void Form1_Activated(object sender, EventArgs e)
        {
            i++;    // i��1���₷.
            label3.Text = i.ToString(); // label3��i.ToString���Z�b�g.
        }
    }
}