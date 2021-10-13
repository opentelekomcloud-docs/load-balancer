HTTP Redirection to HTTPS
=========================

Scenarios
---------

HTTPS is an extension of HTTP. HTTPS encrypts data between a web server and a browser.

If you enable redirection, all HTTP requests to your website are transmitted over HTTPS connections to improve service security.

|image1|

HTTP requests are forwarded to the HTTPS listener as HTTPS requests, which are then routed to backend servers over HTTP.

Prerequisites
-------------

-  An HTTPS listener has been added.
-  An HTTP listener has been added.

Creating a Redirect
-------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image2| and select the desired region and project.
#. Hover on |image3| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the HTTP listener, and click its name.
#. Click **Redirects** and then **Create** on the right.
   

.. _en-us_topic_0118840332__table5765638104311:

   .. table:: **Table 1** Parameters for configuring redirection

      ============= ============================================================== =================
      **Parameter** **Description**                                                **Example Value**
      ============= ============================================================== =================
      Name          Specifies the redirect name.                                   redirect-g8h9
      Redirected To Specifies the HTTPS listener to which requests are redirected. N/A
      Description   Provides supplementary information about the redirect.         N/A
      ============= ============================================================== =================

#. Click **OK**.\ |image4|

   -  If you create a redirect for an HTTP listener, its settings will not take effect except access control.
   -  If you create a redirect for an HTTP listener, the load balancer will return HTTP 301 Move Permanently to the clients.

Modifying a Redirect
--------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image5| and select the desired region and project.
#. Hover on |image6| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the HTTP listener, and click its name.
#. Click **Redirects**, locate the redirect, and click **Modify** in the **Operation** column.
#. In the **Modify Redirect** dialog box, modify the redirect name or description, or select another listener, and click **OK**.

Deleting a Redirect
-------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image7| and select the desired region and project.
#. Hover on |image8| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the listener, and click its name.
#. Click **Redirects**, locate the redirect, and click **Delete** in the **Operation** column.
#. In the **Delete Redirect** dialog box, click **Yes**.

.. |image1| image:: /images/caution_3.0-en-us.png
.. |image2| image:: /images/en-us_image_0241356603.png

.. |image3| image:: /images/en-us_image_0000001120894978.png

.. |image4| image:: /images/note_3.0-en-us.png
.. |image5| image:: /images/en-us_image_0241356603.png

.. |image6| image:: /images/en-us_image_0000001120894978.png

.. |image7| image:: /images/en-us_image_0241356603.png

.. |image8| image:: /images/en-us_image_0000001120894978.png

