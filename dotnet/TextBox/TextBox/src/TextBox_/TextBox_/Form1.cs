using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace TextBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // �e�L�X�g�{�b�N�X��"ABCDE"���Z�b�g.
            textBox1.Text = "ABCDE";    // textBox1.Text��"ABCDE"���Z�b�g.
        }

        private void button2_Click(object sender, EventArgs e)
        {
            // �e�L�X�g�{�b�N�X�̒��g��\��.
            MessageBox.Show(textBox1.Text); // textBox1.Text�̒��g��MessageBox.Show�ŕ\��.
        }
    }
}