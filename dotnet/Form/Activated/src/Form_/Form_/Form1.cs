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
        int i;  // int�^�ϐ�i.
        int j;  // int�^�ϐ�j.
        public Form1()
        {
            InitializeComponent();
            i = 0;  // i��0�ŏ�����.
            j = 0;  // j��0�ŏ�����.
        }

        private void Form1_Activated(object sender, EventArgs e)
        {
            // Form1_Activated���N���邽�т�i��1���₵��label1�ɃZ�b�g.
            i++;    // i��1���₷.
            label1.Text = i.ToString();    // label1.Text��i��i.ToString�ɂ��ăZ�b�g.
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Form1_Load���N���邽�т�j��1���₵��label2�ɃZ�b�g.
            j++;    // j��1���₷.
            label2.Text = j.ToString();    // label2.Text��j��j.ToString�ɂ��ăZ�b�g.
        }
    }
}