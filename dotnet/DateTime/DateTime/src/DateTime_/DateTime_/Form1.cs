using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace DateTime_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            // ���x���Ɍ��ݓ�����\������.
            DateTime dateTime = DateTime.Now;   // DateTime.Now�Ō��ݓ������擾��, dateTime�Ɋi�[.
            label1.Text = dateTime.ToString();  // dateTime.ToString�Ŏ���������ɕϊ���, label1.Text�Ɋi�[.

            // �^�C�}�[�̏����ݒ�ƊJ�n.
            timer1.Interval = 1000; // �Ԋu��1�b.(1000�~���b)
            timer1.Enabled = true;  // �^�C�}�[���L���ɂȂ�, �J�n����.

        }

        // Interval�Őݒ肵���Ԋu���������ɔ�������^�C�}�[�C�x���g.
        private void timer1_Tick(object sender, EventArgs e)
        {

            // ���x���Ɍ��ݓ�����\������.
            DateTime dateTime = DateTime.Now;   // DateTime.Now�Ō��ݓ������擾��, dateTime�Ɋi�[.
            label1.Text = dateTime.ToString();  // dateTime.ToString�Ŏ���������ɕϊ���, label1.Text�Ɋi�[.

        }
    }
}