using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace PictureBox_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // �摜�����[�h��, pictureBox1�ɉ摜���Z�b�g����.
            pictureBox1.Image = Image.FromFile("bitmap1.bmp");  // Image.FromFile��"bitmap1.bmp"�����[�h��, pictureBox1.Image�ɃZ�b�g.
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            // �����摜���c���Ă����烊�\�[�X�������.
            if (pictureBox1.Image != null)  // pictureBox1.Image��null����Ȃ���.
            {
                pictureBox1.Image.Dispose();    // Image.Dispose�Ń��\�[�X���.
                pictureBox1.Image = null;   // Image��null�ɂ��ăR���g���[���ォ��폜.
            }
        }
    }
}