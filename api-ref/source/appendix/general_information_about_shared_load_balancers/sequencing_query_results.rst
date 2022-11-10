:original_name: elb_fl_0005.html

.. _elb_fl_0005:

Sequencing Query Results
========================

APIs v2.0 enable the system to sort queried results based on customized keys by adding the **sort_key** and **sort_dir** parameters to the URL of the list request. **sort_key** specifies the parameter used for sequencing results, and **sort_dir** specifies whether results are displayed in ascending or descending order. These APIs allow sorting query results by multiple criteria. The number of **sort_key** parameters must be equal to that of **sort_dir** parameters. Otherwise, 400 status code is returned.

Example Request
---------------

.. code-block:: text

   GET /v2.0/networks?sort_key=name&sort_dir=asc&sort_key=status&sort_dir=desc

Example Response
----------------

.. code-block::

   {
       "networks": [
           {
               "status": "ACTIVE",
               "subnets": [],
               "name": "liudongtest ",
               "admin_state_up": false,
               "tenant_id": "6fbe9263116a4b68818cf1edce16bc4f",
               "id": "60c809cb-6731-45d0-ace8-3bf5626421a9"
           },
           {
               "status": "ACTIVE",
               "subnets": [
                   "132dc12d-c02a-4c90-9cd5-c31669aace04"
               ],
               "name": "publicnet",
               "admin_state_up": true,
               "tenant_id": "6fbe9263116a4b68818cf1edce16bc4f",
               "id": "9daeac7c-a98f-430f-8e38-67f9c044e299"
           },
           {
               "status": "ACTIVE",
               "subnets": [
                   "e25189a8-54df-4948-9396-d8291ffc92a0"
               ],
               "name": "testnet01",
               "admin_state_up": true,
               "tenant_id": "6fbe9263116a4b68818cf1edce16bc4f",
               "id": "3d42a0d4-a980-4613-ae76-a2cddecff054"
           }
       ]
   }
