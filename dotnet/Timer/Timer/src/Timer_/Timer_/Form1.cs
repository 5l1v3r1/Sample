using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Timer_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            // �^�C�}�[�̏�����.
            timer1.Interval = 5000; // �Ԋu��5�b.(5000�~���b)

        }

        // "�J�n"
        private void menuItem2_Click(object sender, EventArgs e)
        {

            // �^�C�}�[�̊J�n.
            timer1.Enabled = true;  // �^�C�}�[���L���ɂȂ�, �J�n����.

        }

        // "�I��"
        private void menuItem3_Click(object sender, EventArgs e)
        {

            // �^�C�}�[�̒�~.
            timer1.Enabled = false; // �^�C�}�[�������ɂȂ�, �I������.

        }

        // Interval�Őݒ肵���Ԋu���������ɔ�������^�C�}�[�C�x���g.
        private void timer1_Tick(object sender, EventArgs e)
        {

            // "Timer Event!"�ƕ\��.
            MessageBox.Show("Timer Event!");    // MessageBox.Show��"Timer Event!"�ƕ\��.

        }
    }
}