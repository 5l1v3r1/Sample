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
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

            // ���[�h���Ƀe�L�X�g�{�b�N�X��"ABCDE"���Z�b�g.
            textBox1.Text = "ABCDE";    // textBox1.Text��"ABCDE"����.

        }
    }
}