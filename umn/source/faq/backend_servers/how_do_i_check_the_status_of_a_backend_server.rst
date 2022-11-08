:original_name: elb_faq_0041.html

.. _elb_faq_0041:

How Do I Check the Status of a Backend Server?
==============================================

#. Verify that the applications on the backend server are enabled.

   a. Log in to the backend server. (An ECS is used as an example here.)

   b. Check the port status.

      **netstat -ntpl**

      .. note::

         For Windows ECSs, use **netstat -ano** on the CLI to view the port status or server software status.


         .. figure:: /_static/images/en-us_image_0168612036.jpg
            :alt: **Figure 1** Port status

            **Figure 1** Port status

#. Check the network communication of the ECS.

   For example, if the ECS uses port 80, use **curl** to check whether network connectivity is normal.

   |image1|

.. |image1| image:: /_static/images/en-us_image_0238256358.jpg
