using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Application_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            // �A�v���P�[�V�����̏I��
            Application.Exit(); // Application.Exit�ŃA�v���P�[�V����(���b�Z�[�W���[�v)���I������.

        }
    }
}