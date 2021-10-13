How Do I Check the Status of a Backend Server?
==============================================

#. Verify that the applications on the backend server are enabled.

   a. Log in to the backend server. (An ECS is used as an example here.)

   b. Run the following command to check the port status:

      **netstat -ntpl**

      | |image1|\ For Windows ECSs, run the **netstat -ano** command on the CLI to view the port status or server software status.\ **Figure 1** Port status
      | |image2|

#. Check the network communication of the ECS.

   For example, if the ECS uses port 80, run the **curl** command to check whether the communication is normal.

   |image3|

.. |image1| image:: /images/note_3.0-en-us.png
.. |image2| image:: /images/en-us_image_0168612036.jpg

.. |image3| image:: /images/en-us_image_0238256358.jpg

