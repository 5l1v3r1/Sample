using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace MessageBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // ���b�Z�[�W�{�b�N�X�Ńe�L�X�g��\��.
            MessageBox.Show("button1 Clicked!");    // MessageBox.Show��"button1 Clicked!"��\��.
        }
    }
}