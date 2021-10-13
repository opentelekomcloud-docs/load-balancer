Access Logging
==============

Access logs record HTTP and HTTPS requests made to load balancers, and these logs are stored in an OBS bucket. Only public network classic load balancers support access logging.

Before configuring access logging, ensure that you have created a load balancer and OBS bucket. For details, see "Creating a Bucket" in the *Object Storage Service User Guide*.

#. Grant read and write permissions to the ELB administrator.

   a. Log in to the management console. On the **Object Storage Service** page, click the name of the destination bucket.
   b. In the navigation pane on the left, choose **Permissions**.
   c. On the displayed page, click **Bucket ACLs**.
   d. Click **Add** and set the parameters.

   

.. _elb_ug_rzfw_0001__table38812372310:

   .. table:: **Table 1** Parameter description

      ================ =========================================================================== =================
      **Parameter**    **Description**                                                             **Example Value**
      ================ =========================================================================== =================
      Account          Specifies the account ID or account name of the ELB administrator.          N/A
      Access to Bucket Specifies the permissions to read data from or write data to an OBS bucket. Read/Write
      Access to ACL    Allows the authorized user to read or write the bucket ACL.                 Read/Write
      ================ =========================================================================== =================

   e. Click **Save**.

#. Associate the bucket with a load balancer.

   a. Locate the load balancer and click **More** in the **Operation** column.
   b. Select **Configure Access Log**.
   c. In the **Configure Access Log** dialog box, enable access logging.
   d. Select the associated OBS bucket and configure log information.\ **Figure 1** Configure Access Log
      |image1|
      

.. _elb_ug_rzfw_0001__table389515316230:

      .. table:: **Table 2** Parameter description

         +---------------------------------------+---------------------------------------+---------------------------------------+
         | **Parameter**                         | **Description**                       | **Example Value**                     |
         +=======================================+=======================================+=======================================+
         | Enable Logging                        | Whether to enable access logging      | N/A                                   |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | Backup Interval (min)                 | Log backup interval in minutes, which | 60                                    |
         |                                       | is 60 minutes by default              |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | OBS Bucket                            | Destination bucket with read and      | obs01                                 |
         |                                       | write permissions                     |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+
         | Prefix                                | Log storage directory                 | log01                                 |
         |                                       |                                       |                                       |
         |                                       | If this field is left blank, logs     |                                       |
         |                                       | will be saved to the root directory   |                                       |
         |                                       | of the destination bucket.            |                                       |
         +---------------------------------------+---------------------------------------+---------------------------------------+

.. |image1| image:: /images/en-us_image_0152872722.png

