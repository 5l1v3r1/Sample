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
        int k;  // int�^�ϐ�k.
        public Form1()
        {
            InitializeComponent();
            i = 0;  // i��0�ŏ�����.
            j = 0;  // j��0�ŏ�����.
            k = 0;  // k��0�ŏ�����.
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

        private void Form1_Shown(object sender, EventArgs e)
        {
            // Form1_Shown���N���邽�т�k��1���₵��label3�ɃZ�b�g.
            k++;    // k��1���₷.
            label3.Text = k.ToString(); // label3.Text��k��k.ToString�ɂ��ăZ�b�g.
        }
    }
}